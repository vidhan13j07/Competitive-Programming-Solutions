n=input()
s=0
c=0
l=[n]
while 1:
	while n>0:
		a=n%10
		s+=a*a
		n/=10
	n=s
	s=0
	c+=1
	if(n==1):
		break
	else:
		for i in l:
			if i==n:
				c=-2
				n=1
		else:
			l.append(n)
print c	
