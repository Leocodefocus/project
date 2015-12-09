#linux server:192.168.102.88 port nc -l 4444
import socket
addr=('192.168.102.88',4444)
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(addr)
sock.send("Hello server!\n\nYour command:")
data=sock.recv(1024)
while data:
	print '[*] Recv command: ',data
	sock.send("Hello server!\n\nYour command:")
	data=sock.recv(1024)
sock.close()
