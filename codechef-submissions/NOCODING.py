t=int(raw_input())
s='abcdefghijklmnopqrstuvwxyz'
while t>0:
	t-=1
	l=[x for x in raw_input()]
	le=len(l)
	ins=le+1
	for i in xrange(1,le):
		k=s.index(l[i])-s.index(l[i-1])
		if k<0:
			k+=26
		ins+=k
		if ins>11*le:
			print 'NO'
			break
	else:
		print 'YES'
