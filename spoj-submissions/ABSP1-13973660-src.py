t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	s=0
	for i in xrange(n):
		s+=(2*i+1-n)*l[i]
	print s