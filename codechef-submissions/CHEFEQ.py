t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	k=max(l)
	l1=[0]*k
	for i in xrange(n):
		l1[l[i]-1]+=1
	k=max(l1)
	print n-k
