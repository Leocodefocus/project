#client.py
import socket
import sys
host_port=50007
host_ip="192.168.4.77"
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((host_ip,host_port))

while(1):
	cmd=raw_input("Please input cmd:")
	s.sendall(cmd)
	data=s.recv(1024)
	print data
s.close()