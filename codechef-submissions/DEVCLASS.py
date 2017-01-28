t=int(raw_input())
while t>0:
	t-=1
	type=int(raw_input())
	s=[x for x in raw_input()]
	b=s.count('B')
	g=len(s)-b
	ans=0
	if len(s)%2==0:
		if b!=g:
			ans=-1
		else:
			s1,s2,s3,s4=[],[],[],[]
			for i in xrange(b+g):
				if i%2==0:
					if s[i]!='B':
						s1.append(i)
					else:
						s3.append(i)
				else:
					if s[i]!='G':
						s2.append(i)
					else:
						s4.append(i)
			if type==0:
				m=len(s1)
				n=len(s3)
			else:
				m,n=0,0
				for i in xrange(len(s1)):
					m+=abs(s1[i]-s2[i])
				for i in xrange(len(s3)):
					n+=abs(s3[i]-s4[i])
			if m<n:
				ans=m
			else:
				ans=n
	else:
		s1,s2=[],[]
		if b==g+1:
			for i in xrange(b+g):
				if i%2==0 and s[i]!='B':
					s1.append(i)
				elif i%2==1 and s[i]!='G':
					s2.append(i)
		elif g==b+1:
			for i in xrange(b+g):
				if i%2==0 and s[i]!='G':
					s1.append(i)
				elif i%2==1 and s[i]!='B':
					s2.append(i)
		else:
			ans=-1
		if type==0 and ans!=-1:
			ans=len(s1)
		else:
			for i in xrange(len(s1)):
				ans+=abs(s1[i]-s2[i])
	print ans
