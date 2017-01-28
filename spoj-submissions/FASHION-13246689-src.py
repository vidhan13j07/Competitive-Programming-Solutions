t=input()
while(t>0):
	n=input()
	t-=1
	lm=[int(x) for x in raw_input().split()]
	lf=[int(x) for x in raw_input().split()]
	s=0
	lm.sort()
	lf.sort()
	for i in xrange(n):
		s+=lm[i]*lf[i]
	print s
