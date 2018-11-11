# By G S Nitesh Narayana 


set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

# for nam
set nf [open first_out.nam w]
$ns namtrace-all $nf

#f for traceing
set tf [open out_new.tr w]
$ns trace-all $tf

#for using new trace format
$ns use-newtrace

# for finishing properly

proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf

	exec nam first_out.nam &

	exit 0	
}


# making nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# $ns duplex-link $n0 $n1 10Mb 10ms DropTail
# $ns duplex-link $n1 $n2 10Mb 20ms FQ
# $ns duplex-link $n3 $n2 10Mb 20ms RED
# $ns duplex-link $n0 $n3 10Mb 10ms DRR

# $ns duplex-link-op $n0 $n1 orient down
# $ns duplex-link-op $n1 $n2 orient right
# $ns duplex-link-op $n3 $n2 orient up
# $ns duplex-link-op $n0 $n3 orient rights


# not my orientation or experiment the below one
$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 10Mb 20ms FQ
$ns duplex-link $n2 $n3 10Mb 20ms RED
# $ns duplex-link $n0 $n3 10Mb 10ms DRR

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
# $ns duplex-link-op $n0 $n3 orient rights



$ns duplex-link-op $n2 $n3 queuePos 0.5

# # this for the buffer capacity
$ns queue-limit $n2 $n3 20

#set up tcp connection

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink

$ns connect $tcp $sink
$tcp set fid 1
$tcp set packet_size 552

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP


$ns at 1.0 "$ftp start"

$ns at 4.0 "$ftp stop"

$ns at 5.0 "finish"

$ns run



