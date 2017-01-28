t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	l.sort()
	m=l[1]-l[0]
	for i in xrange(1,n-1):
		k=l[i+1]-l[i]
		if k<m:
			m=k
	print m
