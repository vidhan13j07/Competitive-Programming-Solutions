t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[int(x) for x in raw_input().split()]
	l.sort()
	ans=[]
	if n%2==0:
		j=n/2
	else:
		j=n/2+1
	for i in xrange(n):
		if i%2==0:
			ans.append(str(l[i/2]))
		else:
			ans.append(str(l[j+i/2]))
	print " ".join(ans)
