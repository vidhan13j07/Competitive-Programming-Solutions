t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	print len(set(l))
