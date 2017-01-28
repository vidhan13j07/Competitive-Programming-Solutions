import sys 
for i in sys.stdin:
	if int(i)==0:
		print 18
	elif int(i)==1: 
		print 1 
	else: 
		print int(i)*2-2 