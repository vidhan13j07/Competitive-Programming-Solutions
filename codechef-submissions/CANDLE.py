t=int(raw_input())
while t>0:
	t-=1
	l=map(int,raw_input().split())
	m=min(l[1:])
	if m>l[0]:
		print '1'+'0'*(l[0]+1)
	else:
		print str(l[1:].index(m)+1)*(m+1)
