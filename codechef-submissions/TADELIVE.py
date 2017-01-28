n,x,y=map(int,raw_input().split())
l=[int(k) for k in raw_input().split()]
l1=[int(k) for k in raw_input().split()]
s=0
c1=0
c2=0
for i in xrange(n):
	if l[i]>l1[i] and c1<=x:
		s+=l[i]
		c1+=1
	elif l[i]==l1[i]:
		s+=l[i]
		if c1<c2:
			c1+=1
		else:
			c2+=1
	else:
		s+=l1[i]
		c2+=1
print s
