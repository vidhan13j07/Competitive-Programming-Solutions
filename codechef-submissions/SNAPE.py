t=int(raw_input())
while t>0:
	t-=1
	l,b=map(int,raw_input().split())
	print (b*b-l*l)**0.5,
	print (b*b+l*l)**0.5
