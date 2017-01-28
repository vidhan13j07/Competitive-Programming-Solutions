t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[[]]
	l=[[int(raw_input())]]
	for i in xrange(n-1):
		l.append(map(int,raw_input().split()))
	for i in xrange(n-2,-1,-1):
		for j in xrange(i+1):
			l[i][j]+=l[i+1][j] if l[i+1][j]>l[i+1][j+1] else l[i+1][j+1]
	print l[0][0]
