t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	s=l[int(raw_input())-1]
	l.sort()
	print l.index(s)+1
