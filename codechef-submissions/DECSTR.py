t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	s='abcdefghijklmnopqrstuvwxyz'
	s1=""
	if n==25:
		s1=s[:]
	if n>25:
		for i in xrange(n/25):
			s1+=s[:]
		n=n%25
	if n%25!=0:
		s=s[:n+1]
		s1+="".join(s[::])
	print s1[::-1]
