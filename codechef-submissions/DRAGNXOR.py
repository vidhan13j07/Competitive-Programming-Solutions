t=int(raw_input())
while t>0:
	t-=1
	n,a,b=map(int,raw_input().split())
	l1,l2=list(bin(a)),list(bin(b))
	a=l1.count('1')
	b=l2.count('1')
	if a+b==n:
		ans='1'*n
	elif a+b<n:
		ans='1'*(a+b)+'0'*(n-a-b)
	else:
		ans='1'*(2*n-a-b)+'0'*(a+b-n)
	print int(ans,2)
