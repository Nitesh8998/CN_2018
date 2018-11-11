#####################################################################
################http://www.ns2blogger.blogspot.in/###################
#####################################################################

BEGIN {
       sends=0;
       recvs=0;
       routing_packets=0.0;
       droppedBytes=0;
       droppedPackets=0;
       highest_packet_id =0;
       sum=0;
       recvnum=0;
     }
   
  {
  time = $3;
  packet_id = $41;
   
  # CALCULATE PACKET DELIVERY FRACTION
  if (( $1 == "s") &&  ( $35 == "cbr" ) && ( $19=="AGT" )) {  sends++; }
   
  if (( $1 == "r") &&  ( $35 == "cbr" ) && ( $19=="AGT" ))   {  recvs++; }
   
  # CALCULATE DELAY 
  if ( start_time[packet_id] == 0 )  start_time[packet_id] = time;
  if (( $1 == "r") &&  ( $35 == "cbr" ) && ( $19=="AGT" )) {  end_time[packet_id] = time;  }
       else {  end_time[packet_id] = -1;  }
   
  # CALCULATE TOTAL AODV OVERHEAD 
  if (($1 == "s" || $1 == "f") && $19 == "RTR" && ($35 =="AODV" ||$35 =="AOMDV")) routing_packets++;
   
  # DROPPED AODV PACKETS 
  if (( $1 == "d" ) && ( $35 == "cbr" )  && ( $3 > 0 ))
       {
             droppedBytes=droppedBytes+$37;
             droppedPackets=droppedPackets+1;
       }
   
       #find the number of packets in the simulation
          if (packet_id > highest_packet_id)
             highest_packet_id = packet_id;
  }
   
  END {
   
  for ( i in end_time )
  {
  start = start_time[i];
  end = end_time[i];
  packet_duration = end - start;
  if ( packet_duration > 0 )  
  {    sum += packet_duration;
       recvnum++; 
  }
  }
   
     delay=sum/recvnum;
     NRL = routing_packets/recvs;  #normalized routing load 
     PDF = (recvs/sends)*100;  #packet delivery ratio[fraction]
     printf("Send Packets = %.2f\n",sends);
     printf("Received Packets = %.2f\n",recvs);
     printf("Roting Packets = %.2f\n",routing_packets++);
     printf("Packet Delivery Function = %.2f\n",PDF);
     printf("Normalised Routing Load = %.2f\n",NRL);
     printf("Average end to end delay(ms)= %.2f\n",delay*1000);
     printf("No. of dropped data (packets) = %d\n",droppedPackets);
     printf("No. of dropped data (bytes)   = %d\n",droppedBytes);
  }

