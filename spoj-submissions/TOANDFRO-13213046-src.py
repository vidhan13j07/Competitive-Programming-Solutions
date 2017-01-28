while 1:
	n=input()
	if(n==0):
		break
	s=raw_input()
	l=[]
	low=0
	i=1
	while low<(len(s)):
		if(i%2==1):
			l.append(s[low:low+n])
		else:
			l.append(s[low+n-1:low-1:-1])
		low+=n
		i+=1
	s1=""
	low=len(s)/n
	for i in xrange(n):
		for j in xrange(low):
			s1+=l[j][i]
	print s1
