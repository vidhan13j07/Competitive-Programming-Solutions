s=[x for x in raw_input()]
s=s[::-1]
l1=len(s)
l=[]
n=int(raw_input())
while n>0:
	n-=1
	s1=[x for x in raw_input()]
	s2=s1[::-1]
	for i in xrange(l1):
		if s2[i]!=s[i]:
			break
	else:
		l.append("".join(s1))
if len(l)==0:
	print 'Wrong fingerprints!'
else:
	l.sort()
	print len(l)
	for i in l:
		print i