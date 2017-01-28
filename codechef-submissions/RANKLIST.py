t=int(raw_input())
while t>0:
	t-=1
	n,s=map(int,raw_input().split())
	ans=0
	if n==s:
		ans=1
	else:
		p=(n*(n+1))/2
		if s==p:
			ans=n
		elif s>=p-n:
			ans=n-1
		else:
			a=1
			while 1:
				if s-a<0 or s-n<0:
					 break
				else:
					s-=a
				ans+=1
				a+=1
	print n-ans
