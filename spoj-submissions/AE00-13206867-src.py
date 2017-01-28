from math import sqrt
n=input()
s=0
if n>1:
	for i in xrange(1,int(sqrt(n))+1):
		s+=(n/i-i+1)
else:
	s=1
print s
