t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[0 for x in xrange(10001)]
	l1=map(int,raw_input().split())
	for i in l1:
		l[i]+=1
	k=max(l)
	print l.index(k),k
