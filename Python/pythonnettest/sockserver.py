 # -*- coding: utf-8 -*-
"""
author:leo
Date:2016/1/27
Description:Server
"""
import socket
import argparse
import sys

host='localhost' #主机地址
data_payload=2048 #数据包大小
backlog=5 #接收连接的数量

def conn_server(port):
	#创建socket
	sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	#设置端口重用
	sock.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
	#绑定地址，端口
	server_address=(host,port)
	sock.bind(server_address)
	socket_address=sock.getsockname()
	print "Trivial Server launched on socket:%s"%str(socket_address)
	sock.listen(backlog)#监听
	
	while True:
		print "waiting to receive message from client"
		client,address=sock.accept()#接受连接
		data=client.recv(data_payload)#接受数据
		if data:
			print "Data:%s"%data
			client.send(data)#回显数据
			print "sent %s bytes back to %s"%(data,address)
			client.close()
	
if __name__=="__main__":
	#设置命令行参数规则
	parser=argparse.ArgumentParser(description='Socket Server Port Arguments')
	parser.add_argument('--port',action="store",dest="port",type=int,required=False)
	given_args=parser.parse_args()
	port=given_args.port
	conn_server(port)