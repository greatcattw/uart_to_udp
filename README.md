# uart_to_udp
Rx in uart message and Tx out UDP message

# Test#1 Local, UDP message Tx and Rx itself.
![pic](pic/test1a.png)<br>
![pic](pic/test1b.png)<br><br><br>
Run with X86 Ubuntu  
bin_u86\udp.svr.out  8888
bin_u86\udp.cli.out 127.0.0.1 8888
<br>
type something then press [Enter] with udp.cli.out  
udp.svr.out show the message.  
<br>

# Test#2 minicom uart Tx and UDP Rx
![pic](pic/test2.png)<br><br><br>
Run UDP server to Rx UDP message  
bin_u86\udp.svr.out  8888  
<br>
Run minicom with ttyUSB1, 115200, to Tx uart message from ttyUSB1.
<br>
Run bin_u18\uart2udp.out to Rx uart message from ttyUSB0, and send message out over UDP  
![pic](pic/test2a.png)<br>
![pic](pic/test2b.png)<br><br><br>
type something quickly with minicom.
udp.svr.out show the message.  
wait_usec=1001 is a magic number for showing more debug message.  
<br>
# Test#3 arduino uart Tx, mt7688 uart Rx and UDP Tx, PC Rx UDP
![pic](pic/test3.png)<br><br><br>
