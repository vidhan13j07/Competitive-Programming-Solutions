t=int(raw_input())
while t>0:
	t-=1
	n,m=map(int,raw_input().split())
	l=map(int,raw_input().split())
	print "Yes" if sum(l)<=m else "No"
