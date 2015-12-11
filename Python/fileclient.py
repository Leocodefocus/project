import socket
import sys
#host_ip=raw_input('Type in your host addr: ')
#host_port=(int)raw_input('Type in your host port: ')
addr=('localhost',9999)
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(addr)
sock.send("client:Hello server!\n\n")
data=sock.recv(1024)
print 'Get server response: ',data
sock.close()
while True:
	data=raw_input('Your ans: ')
	sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	sock.connect(addr)
	sock.send('client:'+data)
	data=sock.recv(1024)
	print 'Get server response: ',data
	sock.close()
print 'Good bye with server\n\n'