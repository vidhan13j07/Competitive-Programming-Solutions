low='abcdefghijklmnopqrstuvwxyz'
up='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[]
	s=raw_input()
	for i in xrange(0,2*n-2,2):
		l.append([s[i],s[i+1]])
	temp,ans=[],0
	for i in l:
		if low.index(i[0])!=up.index(i[1]):
			k=low[up.index(i[1])]
			if k in temp:
				c=temp.index(k)
				del temp[c]
			else:
				ans+=1
			temp.append(i[0])
	print ans