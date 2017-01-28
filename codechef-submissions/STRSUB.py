t=int(raw_input())
while t>0:
	t-=1
	n,k,q=map(int,raw_input().split())
	s=[x for x in raw_input()]
	if k==1:
		while q>0:
			q-=1
			c,d=raw_input().split()
			print 0
	else:
		d={}
		n0,n1,start,i=0,0,0,0
		while i<n:
			if n0>k or n1>k:
				d[start+1]=i
				if s[start]=='0':
					n0-=1
				else:
					n1-=1
				start+=1
			else:
				if s[i]=='0':
					n0+=1
				else:
					n1+=1
				i+=1
		if n0>k or n1>k:
			d[start+1]=i
			start+=1
		while q>0:
			q-=1
			l,r=map(int,raw_input().split())
			m=r-l+1
			m=(m*(m+1))/2
			if len(d)>0:
				for i in xrange(l,r):
					if i<=start and r>=d[i]:
						m=m-(r-d[i]+1)
					else:
						break
			print m
