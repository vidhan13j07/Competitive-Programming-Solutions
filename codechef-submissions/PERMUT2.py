while 1:
	n=int(raw_input())
	if n==0:
		break
	l=map(int,raw_input().split())
	l=[0]+l
	for i in xrange(1,n+1):
		if l[l[i]]!=i:
			print "not ambiguous"
			break
	else:
		print "ambiguous"
