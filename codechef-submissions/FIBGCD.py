def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)
t=int(raw_input())
while t>0:
	t-=1
	a,b=map(int,raw_input().split())
	k=gcd(a,b)
	a=0
	b=1
	for i in xrange(k):
		c=a+b
		b=a
		a=c
	if k==1:
		print '1'
	else:
		print c%(10**9+7)
