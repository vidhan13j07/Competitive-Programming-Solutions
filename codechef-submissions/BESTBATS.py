from math import factorial
t=int(raw_input())
while t>0:
	t-=1
	l=[int(x) for x in raw_input().split()]
	n=int(raw_input())
	l.sort()
	l=l[::-1]
	k=l[:n]
	m1=l.count(k[-1])
	m2=k.count(k[-1])
	s=1
	for i in xrange(m2+1,m1+1):
		s*=i
	print s/factorial((m1-m2))
