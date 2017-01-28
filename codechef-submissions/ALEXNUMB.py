t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	l1=list(set(l))
	ans=(n*(n-1))//2
	k=n-len(l1)
	ans-=(k*(k+1))//2
	print ans
