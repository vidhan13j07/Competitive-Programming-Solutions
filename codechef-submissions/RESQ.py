t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	for i in xrange(int(n**0.5),0,-1):
		if n%i==0:
			print n/i-i
			break
