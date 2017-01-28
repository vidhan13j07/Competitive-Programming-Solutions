t=input()
while t>0:
	t-=1
	n=input()
	b=n*(n+1)/2
	s=n*b+b-b*(2*n+1)/3
	c=n/2;
	a=c*(c+1)
	if(n%2==0):
		s+=(a*(2*c+1)/3-a/2)
	else:
		s+=(a*(2*c+1)/3+a/2)
	print s
