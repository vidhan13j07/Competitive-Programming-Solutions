t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	for i in xrange(n/4+1):
		if (n-4*i)%7==0:
			print n-4*i
			break
	else:
		print "-1"
