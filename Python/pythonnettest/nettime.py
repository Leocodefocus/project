 # -*- coding: utf-8 -*-
"""
author:leo
Date:2016/1/27
Description:时间服务同步，库 pip install ntplib
"""
import ntplib
from time import ctime

def print_time():
	ntp_client=ntplib.NTPClient()
	response=ntp_client.request('cn.pool.ntp.org')
	print ctime(response.tx_time)
	
if __name__=="__main__":
	print_time()