n=int(raw_input())
l=[int(x) for x in raw_input().split()]
q=int(raw_input())
while q>0:
	q-=1
	a,b=map(int,raw_input().split())
	for i in xrange(a,b):
		if l[i-1]>l[a-1]:
			print "NO"
			break
	else:
		print "YES"
