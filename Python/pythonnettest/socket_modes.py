 # -*- coding: utf-8 -*-
"""
author:leo
Date:2016/1/27
Description:socket阻塞模式和非阻塞模式
"""
import socket
def test_socket_modes():
	s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	s.setblocking(1)#阻塞模式，0 非阻塞模式
	s.settimeout(0.5)
	s.bind(("127.0.0.1",0))
	
	socket_address=s.getsockname()
	print "Trivial Server launched on socket:%s"%str(socket_address)
	while(1):
		s.listen(1)
	
if __name__=="__main__":
	test_socket_modes()
	