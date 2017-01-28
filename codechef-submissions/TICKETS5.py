t=int(raw_input())
while t>0:
	t-=1
	s=[x for x in raw_input()]
	a=s[0]
	b=s[1]
	if a==b:
		print 'NO'
		continue
	for i in xrange(2,len(s)):
		if i%2==0 and s[i]!=a:
			break
		elif i%2==1 and s[i]!=b:
			break
	else:
		print 'YES'
		continue
	print 'NO'
