# By G S Nitesh Narayana 

set ns[new Simulator]

set n0 [$ns node]
set n1 [$ns node]

$ns at 0.0 "$n0 label sender" 
$ns at 0.0 "$n1 label reciever"

set nf [open stop_wait.nam w]
$ns namtrace-all $nf

set tf [open stop_wait.tr w]
$ns trace-all $tf

$ns use-newtrace

$ns duplex-link $n0 $n1 2Mb 210ms DropTail
$ns duplex-link-op $n0 $n1 orient left
$ns queue-limit $n0$ n1 10

#what does this do???

Agent/TCP set nam_tracevar_ true

set tcp[new Agent/TCP]
$tcp set window 5 
$tcp set maxcwnd 2 
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink] 
$ns attach-agent $n1 $sink

$ns connect $tcp $sink

set ftp [new Application/FTP] 
$ftp attach-agent $tcp

$ns add-agent-trace $tcp tcp 
$ns monitor-agent-trace $tcp 
$tcp tracevar cwnd



$ns at 0.1 "$ftp start" 
$ns at 3.0 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n1 $sink" 
$ns at 3.5 "finish"

$ns at 0.0 "$ns trace-annotate \"Stop and Wait with normal operation\""

$ns at 0.05 "$ns trace-annotate \"FTP starts at 0.1\""

$ns at 0.11 "$ns trace-annotate \"Send Packet_0\"" 
$ns at 0.35 "$ns trace-annotate \"Receive Ack_0\"" 
$ns at 0.56 "$ns trace-annotate \"Send Packet_1\"" 
$ns at 0.79 "$ns trace-annotate \"Receive Ack_1\"" 
$ns at 0.99 "$ns trace-annotate \"Send Packet_2\"" 
$ns at 1.23 "$ns trace-annotate \"Receive Ack_2  \"" 
$ns at 1.43 "$ns trace-annotate \"Send Packet_3\"" 
$ns at 1.67 "$ns trace-annotate \"Receive Ack_3\"" 
$ns at 1.88 "$ns trace-annotate \"Send Packet_4\"" 
$ns at 2.11 "$ns trace-annotate \"Receive Ack_4\"" 
$ns at 2.32 "$ns trace-annotate \"Send Packet_5\"" 
$ns at 2.55 "$ns trace-annotate \"Receive Ack_5    \"" 
$ns at 2.75 "$ns trace-annotate \"Send Packet_6\"" 
$ns at 2.99 "$ns trace-annotate \"Receive Ack_6\""

$ns at 3.1 "$ns trace-annotate \"FTP stops\""

proc finish {} { 
 global ns nf 
 $ns flush-trace 
 close $nf

 puts "filtering..." 
 exec tclsh ../ns-allinone-2.1b5/nam-1.0a7/bin/namfilter.tcl A1-stop-n-wait.nam 
        puts "running nam..." 
        exec nam A1-stop-n-wait.nam & 
 exit 0 
}

$ns run 


