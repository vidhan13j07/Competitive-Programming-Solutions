while(1):
	n=input()
	if(n==-1):
		break
	l=[]
	s=0
	c=0
	for i in xrange(n):
		t=input()
		l.append(t)
		s+=t
	k=s/n
	if(float(1.0*s/n)-k==0.0):
		l.sort()
		i=0
		f=n-1
		while(i<f):
			dif=k-l[i]
			if(dif+k<l[f]):
				c+=dif
				l[f]-=dif
				l[i]=k
				i+=1
			elif(dif+k>l[f]):
				c+=l[f]-k
				l[i]+=l[f]-k
				l[f]=k
				f-=1
			else:
				l[f]=k
				l[i]=k
				f-=1
				i+=1
				c+=dif
	else:
		c=-1
	print c	
				
			
