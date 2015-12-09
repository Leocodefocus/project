import httplib,urllib
params=urllib.urlencode({'account':'admin','password':'admin888'})
headers={'Content-Type':"application/x-www-form-urlencode",
			'Accept':'text/plain'}
conn=httplib.HTTPConnection("192.168.102.88:80")
conn.request("POST","index.php",params,headers)
response=conn.getresponse()
print response.status,response.reason
print response.read()
conn.close()
