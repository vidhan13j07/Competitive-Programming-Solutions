t=int(raw_input())
while t>0:
	t-=1
	l1=["" for _ in xrange(21)]
	n=int(raw_input())
	l=raw_input().split()
	ma=0
	ans=""
	for i in xrange(0,len(l[0])):
		s=""
		for j in xrange(i,len(l[0])):
			s+=l[0][j]
			fl=1
			for k in xrange(1,len(l)):
				if s not in l[k]:
					fl=0
			if fl:
				le=len(s)
				if l1[le]=="":
					l1[le]=s
				else:
					l1[le]=min(l1[le],s)
				#print s,l1
	for i in xrange(20,0,-1):
		if l1[i]!="":
			ans=l1[i]
			break
	print ans
