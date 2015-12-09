#server.py
import socket
import sys
import commands
host_ip="192.168.4.77"
host_port=50007
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((host_ip,host_port))
s.listen(1)
while 1:
	(conn,addr)=s.accept()
	print 'Connected by ',addr
	while 1:
		data=conn.recv(1024)
		cmd_status,cmd_result=commands.getstatusoutput(data)
		if len(cmd_result.strip())==0:
			conn.sendall('Done.')
		else:
			conn.sendall(cmd_result)
	conn.close()