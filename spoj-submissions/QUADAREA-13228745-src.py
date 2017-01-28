from math import sqrt
t=input()
while t>0:
	t-=1
	a,b,c,d=map(float,raw_input().split())
	k=sqrt((a+b+c-d)*(a+b-c+d)*(a-b+c+d)*(-a+b+c+d))
	print k/4
