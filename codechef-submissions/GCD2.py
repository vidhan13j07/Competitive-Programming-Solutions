def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)
t=int(raw_input())
while t>0:
	t-=1
	a,b=map(int,raw_input().split())
	print gcd(a,b)
