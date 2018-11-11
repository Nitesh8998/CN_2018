# By G S Nitesh Narayana 
set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nf [open ethernet_out.nam w]
$ns namtrace-all $nf

set tf [open ethernet_trace.tr w]
$ns trace-all $tf

$ns use-newtrace

proc finish {} {
    global ns nf tf
    $ns flush-trace
    close $nf
    close $tf

    exec nam ethernet_out.nam &

    exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]



# explixitly making lan 
# connecting some nodes to a hub , connecting other nodes to another hub
# then connecting both using a switch this makes a lan
# make lan helps to do so
# other things  are similiar

$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n1 $n2 10Mb 20ms FQ
$ns duplex-link $n2 $n3 10Mb 20ms RED

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

$ns make-lan " $n3 $n4 $n5 $n6" 4Mb 20ms LL 

# here the queue can again be drop tail 

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n5 $sink

$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 1.0 "$ftp start"
$ns at 5.0 "$ftp stop"
$ns at 5.5 "finish"
$ns run