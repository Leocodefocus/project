"""
author:leo
Date:2016/1/26
Description:find net service name by port
"""
import socket

def find_service_name():
    protocolname='tcp'
    for port in [80,25]:
        print "Port:%s=>service name:%s"%(port,socket.getservbyport(port,protocolname))
    print "Port:%s =>service name:%s"%(53,socket.getservbyport(53,'udp'))
if __name__=='__main__':
    find_service_name()