t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	k=sum(l)//(n-1)
	for i in l:
		print k-i,
	print
