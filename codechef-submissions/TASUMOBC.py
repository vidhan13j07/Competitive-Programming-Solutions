from math import factorial
t=input()
while t>0:
	t-=1
	n=input()
	s=0
	for i in xrange(n+1):
		s+=((factorial(n)/(factorial(i)*factorial(n-i)))%3)
	s=s%1000000007
	print s
