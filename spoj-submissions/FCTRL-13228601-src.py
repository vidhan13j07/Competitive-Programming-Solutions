t=input()
while t>0:
	t-=1
	n=input()
	c=0
	q=5
	while(q<=n):
		c+=n/q
		q*=5
	print c
