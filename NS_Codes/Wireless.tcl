# By G S Nitesh Narayana ( through an online tutorial )



set val(chan)       Channel/WirelessChannel     ; #ChannelType
set val(prop)       Propagation/TwoRayGround    ; # radio-prpagation model read on it
set val(netif)      Phy/WirelessPhy             ; # network interface type
set val(mac)        Mac/802_11                  ; # MAC type
set val(ifq)        Queue/DropTail/PriQueue     ; # interface queue type
set val(ll)         LL                          ; # link layer type
set val(ant)        Antenna/OmniAntenna         ; # antenna model omni directional -  sphere
set val(ifqlen)     50                          ; # mac packet inif
set val(nn)         2                           ; # number of mobile nodes
set val(rp)          AODV                        ; # Routing protocol
set val(x)          500                         ; # in meters
set val(y)          500                         ; # same




set ns [new Simulator]

set nf [open wireless_nam.nam w]
$ns namtrace-all-wireless $nf $val(x) $val(y)

set tf [open wireless_trace.tr w]
$ns trace-all $tf            ; # what area we want to show in animation

$ns use-newtrace

# since  its a wireless net we  need to create a topgraphy

set topo [new Topography]
$topo load_flatgrid $val(x) $val(y)         ; # the grid is on the floor 2D 

#Generals operations director GOD creation
# handles the packet exchange and routines as wireless nodes are autnomous
# its not nmandatory but as a safe side 
# if the node doesnt know what to do its better this wat

create-god $val(nn)

#next we set the channel for communications
# need not be the same channel so can have different values
set channel1 [new $val(chan)]
set channel2 [new $val(chan)]

$ns node-config -adhocRouting $val(rp) \
                -llType       $val(ll)  \
                -macType      $val(mac) \
                -ifqType      $val(ifq) \
                -ifqLen       $val(ifqlen)  \
                -antType      $val(ant)     \
                -propType     $val(prop)    \
                -phyType      $val(netif)   \
                -topoInstance $topo         \
                -agentTrace ON              \
                -macTrace   ON              \
                -movementTrace ON           \
                -channel      $channel1

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

# node size should also be given!!

$ns initial_node_pos $n0 10
$ns initial_node_pos $n2 30
$ns initial_node_pos $n3 50
$ns initial_node_pos $n1 10
$ns initial_node_pos $n4 20
$ns initial_node_pos $n5 70

# for disabling the random motion 
# hence they will move in the shortest possible direction

# for loop
# for {set i 0 } {$i <$val(nn) } {incr i}

$n0 random-motion 0
$n1 random-motion 0
$n2 random-motion 0
$n3 random-motion 0
$n4 random-motion 0
$n5 random-motion 0

# intitial coordinates of the nodes

$n0 set X_ 10.0
$n0 set Y_ 20.0
$n0 set Z_ 0.0

$n1 set X_ 210.0
$n1 set Y_ 220.0
$n1 set Z_ 0.0

$n2 set X_ 110.0
$n2 set Y_ 210.0
$n2 set Z_ 0.0

$n3 set X_ 120.0
$n3 set Y_ 220.0
$n3 set Z_ 0.0

$n4 set X_ 120.0
$n4 set Y_ 200.0
$n4 set Z_ 0.0

$n5 set X_ 100.0
$n5 set Y_ 10.0
$n5 set Z_ 0.0


# now mobitty of the nodes
# at what time , which node where to and what speed

$ns at 1.0 "$n1 setdest 490.0 340.0 25.0"
$ns at 1.0 "$n4 setdest 390.0 130.0 5.0"
$ns at 1.0 "$n5 setdest 190.0 440.0 15.0"

$ns at 20.0 "$n5 setdest 100.0 200.0 25.0"

set tcp [new Agent/TCP]
set sink [new Agent/TCPSink]

$ns attach-agent $n0 $tcp
$ns attach-agent $n5 $sink
$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 1.0 "$ftp start"

set udp [new Agent/UDP]
set null [new Agent/Null]
$ns attach-agent $n2 $udp
$ns attach-agent $n3 $null

$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$ns at 1.2 "$cbr start"

$ns at 30.0 "finish"

proc finish {} {
    global ns tf nf
    $ns flush-trace
    close $tf
    close $nf

    exec nam wireless_nam.nam &
    exit 0
}

puts "Starting Simulation"
$ns run