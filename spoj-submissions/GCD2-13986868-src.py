from fractions import gcd
t=int(input())
while t>0:
	t-=1
	a,b=map(int,input().split())
	print (gcd(a,b))