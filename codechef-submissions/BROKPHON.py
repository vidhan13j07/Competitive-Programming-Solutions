t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=map(int,raw_input().split())
	if l[0]!=l[1]:
		ans=1
	else:
		ans=0
	for i in xrange(1,n-1):
		if l[i]!=l[i-1] or l[i]!=l[i+1]:
			ans+=1
	if l[i]!=l[i+1]:
		ans+=1
	print ans
