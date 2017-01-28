t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	s=0
	k=5
	while n>=k:
		s+=n/k
		k*=5
	print s
