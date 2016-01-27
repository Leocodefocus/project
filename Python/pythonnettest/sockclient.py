 # -*- coding: utf-8 -*-
"""
author:leo
Date:2016/1/27
Description:Client
"""

import socket
import argparse
import sys
#主机名
host='localhost'

def echo_client(port):
	#创建socket
	sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	#连接主机
	server_address=(host,port)
	print "Connecting to %s port %s"%server_address
	sock.connect(server_address)
	
	try:
		message="Test message.This will be echoed"
		print "Sending %s"%message
		#发送信息
		sock.sendall(message)
		#接收信息
		amount_received=0
		amount_expected=len(message)
		
		while amount_received<amount_expected:
			data=sock.recv(16)
			amount_received+=len(data)
			print "Received:%s"%data
	except socket.errno,e:
		print "Socket error:%s"%str(e)
	except Exception,e:
		print "Other exception:%s"%str(e)
	finally:
		print "Closing connection to the server"
		sock.close()

if __name__=="__main__":
	parser=argparse.ArgumentParser(description='Socket Server Port Arguments')
	parser.add_argument('--port',action="store",dest="port",type=int,required=False)
	given_args=parser.parse_args()
	port=given_args.port
	echo_client(port)
		
		