t=int(raw_input())
while t>0:
	t-=1
	s=[x for x in raw_input().strip()]
	s=s[::-1]
	n=int(raw_input())
	n*=12
	ans=0
	while n>0:
		for i in s:
			if i=='T':
				n-=2
			elif i=='S':
				n-=1
			if n<=0:
				break
		if n>0:
			ans+=n
	print ans
