import subprocess

host = "192.168.0.101"

ping = subprocess.Popen(
   ["ping", "-c", "4", host],
   stdout = subprocess.PIPE,
   stderr = subprocess.PIPE
   )

out, error = ping.communicate()
print out
