t=int(raw_input())
a,b,c,ans=0,0,0,1
while t>0:
	t-=1
	s=raw_input()
	if s=='1/4':
		a+=1
	elif s=='1/2':
		b+=1
	else:
		c+=1
ans+=c
a-=c
if a<0:
	ans+=b//2
	if b%2==1:
		ans+=1
else:
	b+=a/2
	ans+=b//2
	if b%2==1:
		ans+=1
	else:
		if a%2==1:
			ans+=1
print ans