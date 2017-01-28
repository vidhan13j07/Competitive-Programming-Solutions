n,m,k=map(int,raw_input().split())
l=[0]+[int(x) for x in raw_input().split()]
for i in xrange(k):
	a,b=map(int,raw_input().split())
	d={}
	l1=l[a:b+1]
	for i in xrange(len(l1)):
		if l1[i] in d.keys():
			d[l1[i]].append(i)
		else:
			d[l1[i]]=[i]
	ans=0
	for i in d.keys():
		ans=max(ans,d[i][-1]-d[i][0])
	print ans
