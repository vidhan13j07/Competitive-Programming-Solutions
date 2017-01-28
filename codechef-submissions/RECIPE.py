def gcd(m,n):
	if n==0:
		return m
	else:
		return gcd(n,m%n)
t=int(raw_input())
while t>0:
	t-=1
	l=map(int,raw_input().split())
	n=l[0]
	l=l[1:]
	s=gcd(l[0],l[1])
	for i in xrange(2,n):
		s=gcd(s,l[i])
	l=[str(x/s) for x in l]
	print " ".join(l)
