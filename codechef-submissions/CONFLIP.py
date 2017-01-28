t=int(raw_input())
while t>0:
	t-=1
	g=int(raw_input())
	while g>0:
		g-=1
		i,n,q=map(int,raw_input().split())
		if i==1:
			if q==1:
				print n/2
			else:
				print n-n/2
		else:
			if q==1:
				print n-n/2
			else:
				print n/2
