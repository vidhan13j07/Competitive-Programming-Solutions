t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	while 1:
		m=min(l)
		if l.count(m)==n:
			break
		for i in xrange(n):
			if l[i]%m==0:
				l[i]=m
			else:
				l[i]=l[i]%m
	print m
