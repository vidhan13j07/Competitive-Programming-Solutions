t=int(raw_input())
while t>0:
	t-=1
	n,k=map(int,raw_input().split())
	a=[int(x) for x in raw_input().split()]
	b=[int(x) for x in raw_input().split()]
	s=0
	for i in xrange(n):
		s1=b[i]*(k//a[i])
		if s1>s:
			s=s1
	print s
