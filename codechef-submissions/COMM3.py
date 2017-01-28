t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[]
	for _ in xrange(3):
		l.append(map(int,raw_input().split()))
	a=((l[0][0]-l[1][0])**2+(l[0][1]-l[1][1])**2)**0.5
	b=((l[1][0]-l[2][0])**2+(l[2][1]-l[1][1])**2)**0.5
	c=((l[0][0]-l[2][0])**2+(l[2][1]-l[0][1])**2)**0.5
	if (a<=n and c<=n) or b<=n:
		print "yes"
	else:
		print "no"
