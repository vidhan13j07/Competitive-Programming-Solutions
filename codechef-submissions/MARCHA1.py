t=int(raw_input())
while t>0:
	t-=1
	n,m=map(int,raw_input().split())
	l=[int(raw_input())]
	for i in xrange(n-1):
		k=int(raw_input())
		l1=l[:]
		for j in l:
			l1.append(j+k)
		l1.append(k)
		l=list(set(l1))
	if m in l:
		print "Yes"
	else:
		print "No"
