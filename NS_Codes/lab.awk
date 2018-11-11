BEGIN {

	sent = 0;
	recieved = 0;
	sum = 0;
	recv_num = 0;
}

{
	time = $3;
	packet_id =$43;

	if(($1 == "r")) recieved++;

	if(($1 == "+")) sent++;

	if( start_time[packet_id] == 0) start_time[packet_id]=0;
	if(($1 == "r")) 
		end_time[packet_id] = time ;
	else
		end_time[packet_id] = -1 ;

}

END {
	for( i in end_time)
	{
		start = start_time[i];
		end = end_time[i];
		packet_duration = end - start ;
		if( packet_duration > 0)
		{
			sum += packet_duration;
			recv_num++;
		}
	}

	printf("Sum :%d recv_num:%d",sum , recv_num);
	delay = sum / recv_num ;
	pdf = (recieved / sent) * 100 ;
	printf("packet id :%d \n",packet_id);
	printf("Send Packets = %.2f\n",sent);
    printf("Received Packets = %.2f\n",recieved);
	printf("Packet delivery ratio is : %.2f \n",pdf );
	printf("Average packet end to end delivery is %2.f (ms)\n",delay);

}