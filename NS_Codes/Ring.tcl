# By G S Nitesh Narayana 
set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

# for nam
set nf [open Ring_out.nam w]
$ns namtrace-all $nf

#f for traceing
set tf [open out.tr w]
$ns trace-all $tf

# for finishing properly

proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf

	exec nam Ring_out.nam &

	exit 0	
}


# making nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
# $ns duplex-link $n0 $n1 10Mb 10ms DropTail
# $ns duplex-link $n1 $n2 10Mb 20ms FQ
# $ns duplex-link $n3 $n2 10Mb 20ms RED
# $ns duplex-link $n0 $n3 10Mb 10ms DRR

# $ns duplex-link-op $n0 $n1 orient down
# $ns duplex-link-op $n1 $n2 orient right
# $ns duplex-link-op $n3 $n2 orient up
# $ns duplex-link-op $n0 $n3 orient rights


# not my orientation or experiment the below one
$ns duplex-link $n0 $n1 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 10Mb 20ms FQ
$ns duplex-link $n2 $n3 10Mb 20ms RED
$ns duplex-link $n3 $n4 10Mb 10ms DRR
$ns duplex-link $n4 $n5 10Mb 10ms DRR
$ns duplex-link $n5 $n6 10Mb 10ms DRR
$ns duplex-link $n6 $n7 10Mb 10ms DRR
$ns duplex-link $n7 $n0 10Mb 20ms RED

$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient right-up
$ns duplex-link-op $n3 $n4 orient left-up
$ns duplex-link-op $n4 $n5 orient up
$ns duplex-link-op $n5 $n6 orient left
$ns duplex-link-op $n6 $n7 orient left-down
$ns duplex-link-op $n7 $n0 orient left-down

# $ns duplex-link-op $n5 $n0 orient right-down



$ns duplex-link-op $n7 $n0 queuePos 0.5
$ns duplex-link-op $n5 $n6 queuePos 0.5
$ns duplex-link-op $n6 $n7 queuePos 0.5

$ns duplex-link-op $n0 $n1 queuePos 0.5
$ns duplex-link-op $n1 $n2 queuePos 0.5
$ns duplex-link-op $n2 $n3 queuePos 0.5
$ns duplex-link-op $n3 $n4 queuePos 0.5
$ns duplex-link-op $n4 $n5 queuePos 0.5

# # this for the buffer capacity
$ns queue-limit $n7 $n0 20

#set up tcp connection

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink

$ns connect $tcp $sink
$tcp set fid 2
$tcp set packet_size 552

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP


$ns at 1.0 "$ftp start"

$ns at 4.0 "$ftp stop"

$ns at 5.0 "finish"

$ns run



