t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	n-=2
	ans=2
	k=2
	while n>0:
		n-=k
		ans+=1
		k*=2
	print ans