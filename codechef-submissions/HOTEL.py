t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	r=[int(x) for x in raw_input().split()]
	l.sort()
	r.sort()
	i,ans,j,c=0,0,0,0
	while i<n:
		if l[i]==r[j]:
			i+=1
			j+=1
			
		elif l[i]<r[j]:
			c+=1
			if c>ans:
				ans=c
			i+=1
		else:
			c-=1
			j+=1
	print ans
