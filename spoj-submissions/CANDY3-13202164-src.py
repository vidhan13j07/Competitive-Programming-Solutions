t=input()
while t>0:
	t-=1
	#try:
	k=raw_input()
	#except EndOfFile:	
	n=input()
	s=0
	l=[]
	for i in xrange(n):
		s+=input()
	if s%n==0:
		print "YES"
	else:
		print "NO"
