def pal(s):
	l=len(s)
	if l==1:
		return 1
	elif l==0:
		return 0
	if not pal1(s):
		return 0
	return 1+pal(s[:l/2])
def pal1(s):
	l=len(s)
	for i in xrange(l/2):
		if s[i]!=s[l-i-1]:
			break
	else:
		return 1
	return 0
t=int(raw_input())
while t>0:
	t-=1
	s=[x for x in raw_input()]
	l=len(s)
	n=0
	for i in xrange(l):
		for j in xrange(i,l):
			n+=pal(s[i:j+1])
	print n
