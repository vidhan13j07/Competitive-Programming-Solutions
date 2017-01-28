t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	ans=0
	for i in xrange(1,int(n**0.5)+1):
		if n%i==0:
			if i!=n//i:
				ans+=(i+n//i)
			else:
				ans+=i
	print ans
