t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	s=1
	max=l[0]
	for i in xrange(1,n):
		if l[i]<max:
			max=l[i]
			s+=1
	print s
