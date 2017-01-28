t=int(raw_input())
while t>0:
	t-=1
	n,m=map(int,raw_input().split())
	l=raw_input().split()
	l1=[str(x) for x in xrange(1,n+1)]
	for i in l:
		l1.remove(i)
	print " ".join(l1[::2])
	print " ".join(l1[1::2])
