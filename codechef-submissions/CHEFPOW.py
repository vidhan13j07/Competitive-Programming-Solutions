n=input()
s=bin(n)
k=2
for i in xrange(len(s)-2,1,-1):
	if s[i]=='1':
		print k,
	k*=2
