while(1):
	n=float(raw_input())
	if(n==0.0):
		break
	s=0.0
	for i in xrange(2,300):
		s+=(1.0/i)
		if(s>n):
			break
	print "%d card(s)" %(int(i-1.0))
