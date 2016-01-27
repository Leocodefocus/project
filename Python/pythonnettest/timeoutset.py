 # -*- coding: utf-8 -*-
"""
author:leo
Date:2016/1/26
Description:获取超时时间和设置超时时间
"""
import socket

def test_socket_timeout():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    print "Default socket timeout:%s"%s.gettimeout()
    s.settimeout(100)
    print "Current socket timeout:%s"%s.gettimeout()
if __name__=='__main__':
    test_socket_timeout()