t=int(raw_input())
while t>0:
	t-=1
	l=[x for x in raw_input()]
	a,b=0,0
	for i in xrange(len(l)):
		if i%2==0:
			if l[i]=='+':
				a+=1
			else:
				b+=1
		elif i%2==1:
			if l[i]=='-':
				a+=1
			else:
				b+=1
	if a>b:
		print b
	else:
		print a
