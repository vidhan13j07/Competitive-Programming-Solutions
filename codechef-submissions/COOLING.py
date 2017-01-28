t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	l1=[int(x) for x in raw_input().split()]
	l.sort()
	l1.sort()
	s,j=0,0
	for i in xrange(len(l)):
		if l[j]<=l1[i]:
			s+=1
			j+=1
	print s
