"""
author:leo
Date:2016/1/26
Description:get and print host machine's name and ip
            help information get by accessing http://docs.python.org/3/library/socket.html
            or help(socket.gethostname)
"""
import socket
def print_machine_info():
    host_name=socket.gethostname()
    print "Host name:%s"%host_name
    host_ip=socket.gethostbyname(host_name)
    print "IP address:%s"%host_ip
def print_remotehost_ip():
    remote_host="www.baidu.com"
    try:
        print "%s's IP address:%s"%(remote_host,socket.gethostbyname(remote_host))
    except socket.error,err_msg:
        print "%s:%s"%(remote_host,err_msg)
if __name__=='__main__':
    print "local host info:"
    print_machine_info()
    print "\nremote host info:"
    print_remotehost_ip()