for j in xrange(10):
	c=1
	s=raw_input()
	for i in s:
		if i=='T' or i=='D' or i=='L' or i=='F':
			c*=2
	print c
