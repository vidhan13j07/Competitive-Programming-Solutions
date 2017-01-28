t=int(raw_input())
while t>0:
	t-=1
	n,k=map(int,raw_input().split())
	if k==0:
		m=n*(n+1)/2+1
		if m%2==0:
			s="Mom"
		else:
			s="Chef"
	else:
		l=[0]*n
		l1=map(int,raw_input().split())
	print s
