t=int(raw_input())
while t>0:
	t-=1
	m,k,n=map(int,raw_input().split())
	l=[0 for _ in xrange(m+1)]
	for i in map(int,raw_input().split()):
		l[i]+=1
	for i in map(int,raw_input().split()):
		l[i]+=1
	a,b=0,0
	for i in xrange(1,m+1):
		if l[i]==0:
			a+=1
		elif l[i]==2:
			b+=1
	print b,a
