t=int(raw_input())
while t>0:
	t-=1
	l=raw_input().strip()
	print len(l)-l.count('4')-l.count('7')
