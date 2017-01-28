t=int(raw_input())
while t>0:
	t-=1
	s=raw_input()
	l=len(s)
	l1=s[:l/2]
	if l%2==0:
		l2=s[l/2:]
	else:
		l2=s[l/2+1:]
	a=list('abcdefghijklmnopqrstuvwxyz')
	b=[0 for x in xrange(26)]
	c=[0 for x in xrange(26)]
	for i in xrange(l/2):
		b[a.index(l1[i])]+=1
		c[a.index(l2[i])]+=1
	for i in xrange(26):
		if b[i]!=c[i]:
			print "NO"
			break
	else:
		print "YES"
