t=int(raw_input())
while t>0:
	t-=1
	n,k=map(int,raw_input().split())
	l=map(int,raw_input().split())
	l.sort()
	if k==1:
		s=0
	else:
		s=10**10
		for i in xrange(n-k+1):
			s=min(s,l[i+k-1]-l[i])
	print s