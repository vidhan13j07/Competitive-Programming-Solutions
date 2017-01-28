t=int(raw_input())
while t>0:
	t-=1
	a,b=map(int,raw_input().split())
	print str(max(a,b))+" "+str(a+b)
