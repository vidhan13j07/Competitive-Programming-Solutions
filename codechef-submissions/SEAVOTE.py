t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	s=0
	for i in l:
		if i!=0:
			s+=i
		else:
			n-=1
	s1=s-n
	if(s1>=100-n and s1<100 and s>=100 and s<100+n):
		print "YES"
	else:
		print "NO"
