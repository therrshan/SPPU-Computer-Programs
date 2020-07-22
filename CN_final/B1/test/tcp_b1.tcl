#Create simulator Object
set ns [new Simulator]

#define different colors for data
$ns color 1 Red
$ns color 2 Blue

#Open NAM tracefile

set nf [open tcp_b1.nam w]
$ns namtrace-all $nf

#define finish procedure
proc finish {} {
	global ns nf
	$ns flush-trace
	#close na trace file
	close $nf
	#execute Nam on trace file
	exec nam tcp_b1.nam &
	exit 0
}

#create 3 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

#create links between nodes
$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

#Set Queue Size limit (n1-n2) 10
$ns queue-limit $n1 $n2 10
$ns queue-limit $n2 $n1 7
#Give Positioning to the nodes
$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient right

#monitor the queue for link (n1-n2)
$ns duplex-link-op $n1 $n2 queuePos 0.5

#set Up TCP Connection
set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 1


#setup FTP Over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

#not necessary to do.just for demo extra code starts
#second connection to increase traffic

set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
$ns attach-agent $n2 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n0 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 2

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

#extra code ends here


#scehdule events for FTP agents
$ns at 0.1 "$ftp start"
$ns at 0.2 "$ftp1 start"
$ns at 2.7 "$ftp stop"
$ns at 2.8 "$ftp1 stop"

#detach agents not necessary to write but good practise
$ns at 3 "#ns detach-agent $n0 $tcp; $ns detach-agent $n2 $sink"

#call finish procedure
$ns at 3.2 "finish"

puts "TCP B2- http://way2techin.blogspot.com"
#RUn the simulation
$ns run
