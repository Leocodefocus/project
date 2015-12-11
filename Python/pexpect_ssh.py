from pexpect import pxssh
from pexpect import popen_spawn
import getpass
try:
	#s=pxssh.pxssh()
	hostname=raw_input('hostname: ')
	username=raw_input('username: ')
	password=getpass.getpass('password: ')
	s=pexpect.spawn('ssh'+username+'@'+hostname,maxread=5000)
	s.sendline('uptime') #run a command
	s.prompt() #match the prompt
	print(s.before)		#print everything before the prompt
	s.sendline('ls -l')
	s.prompt()
	print(s.before)
	s.logout()
except pxssh.ExceptionPxssh as e:
	print("pxssh failed on login.")
	print(e)