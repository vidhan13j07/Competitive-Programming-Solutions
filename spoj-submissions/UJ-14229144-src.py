def power(a,b):
	x=1
	while b:
		if b&1:
			x=x*a
		a*=a
		b>>=1
	return x
while 1:
	n,d=map(int,raw_input().split())
	if n==0 and d==0:
		break
	print power(n,d)