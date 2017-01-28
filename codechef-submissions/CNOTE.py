t=int(raw_input())
while t>0:
	t-=1
	x,y,k,n=map(int,raw_input().split())
	if x<=y:
		c=1
	else:
		c=0
	for i in xrange(n):
		a,b=map(int,raw_input().split())
		if (x-y-a<=0 or x-a<=0) and b<=k:
			c=1
	if c==1:
		print "LuckyChef"
	else:
		print "UnluckyChef"
