t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[]
	for _ in xrange(n):
		l.append(raw_input())
	for i in sorted(l):
		print i