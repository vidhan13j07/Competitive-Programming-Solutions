def rev(x):
	return int(str(x)[::-1])
t=input()
while t>0:
	t-=1
	a,b=map(int,raw_input().split())
	a=rev(a)
	b=rev(b)
	a+=b
	print rev(a)
