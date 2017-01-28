t=input()
while t>0:
	t-=1
	a,b=map(int,raw_input().split())
	m=a%10
	if(b==0):
		s=1
	else:
		b=b%4
		if b==0:
			b=4
		s=a**b
	print s%10
