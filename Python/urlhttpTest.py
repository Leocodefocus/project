#
#usage:python urlhttp.py [url]
#
import urllib,urllib2
import sys
url='http://'+sys.argv[1]
header={"User-Agent":"Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN;rv:1.9",
		"Accept":"text/plain"}
req=urllib2.Request(url,headers=header)
try:
	response=urllib2.urlopen(req)
	data=response.read()
except urllib2.HTTPError as e:
	print 'http error code:',e.code
	exit(0)
if data is not None:
	print data
