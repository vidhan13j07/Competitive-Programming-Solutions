t=int(raw_input())
while t>0:
	t-=1
	n,m=map(int,raw_input().split())
	l=[int(x) for x in raw_input().split()]
	l.sort()
	m=min(m,abs(n-m))
	print sum(l[m:])-sum(l[:m])
