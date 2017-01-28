t=int(raw_input())
while t>0:
	t-=1
	s,c,k=map(int,raw_input().split())
	ans=0
	if k==1:
		if s==0 and c==0:
			ans=0
		elif s==0 and c!=0:
			ans+=2**(c+1)-2
		elif s>=c+1:
			ans+=2**s+1
		else:
			ans+=2**s+1+2**(s-k+1)*(2**(c-s+k)-1)
	else:
		if k<=s:
			ans+=2**(s-k+1)+1
			if s>1 and c>s-k:
				ans+=2**(s-k+1)
	print ans
