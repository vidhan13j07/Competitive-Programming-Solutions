t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	s1,s2=0,0
	for i in xrange(1,n):
		if l[i-1]>l[i]:
			s1+=1
	l1=l[:]
	l1.sort()
	for i in l:
		k=l1.index(i)
		s2+=k
		del l1[k]
	if s1==s2:
		print "YES"
	else:
		print "NO"
