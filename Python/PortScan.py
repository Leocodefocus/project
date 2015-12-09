#!/usr/bin/python
#PortScan.py

import os
import socket

s=socket.socket()
for port in range(20,100):
	try:
		print "[+]Attempting to connect 127.0.0.1:"+str(port)
		s.connect(('127.0.0.1',port))
		s.send('Primal Security\n')
		banner=s.recv(1024)
		if banner:
			print '[+]Port:'+str(port)+' Open:'+banner
		s.close()
	except:pass

