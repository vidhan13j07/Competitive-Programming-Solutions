def gcd(n,m):
	if(m==0):
		return n
	else:
		return gcd(m,n%m)
t=input()
while t>0:
	t-=1
	n,q=map(int,raw_input().split())
	l=[int(x) for x in raw_input().split()]
	l1=[l[0]]
	a=len(l)
	l2=[l[a-1]]
	for i in xrange(1,a):
		l1.append(gcd(l[i],l1[i-1]))
		l2.append(gcd(l[a-i-1],l2[i-1]))
	while q>0:
		q-=1
		c,d=map(int,raw_input().split())
		if c==1:
			s=l2[a-d-1]
		elif d==a:
			s=l1[c-2]
		else:
			s=gcd(l1[c-2],l2[a-d-1])
		print s
