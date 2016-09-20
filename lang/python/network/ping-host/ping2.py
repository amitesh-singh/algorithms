import subprocess
import shlex

command_line = "ping -c 1 www.google.com"
args = shlex.split(command_line)
try:
   subprocess.check_call(args,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
   print "Website is there."
except subprocess.CalledProcessError:
   print "Couldn't get a ping."

