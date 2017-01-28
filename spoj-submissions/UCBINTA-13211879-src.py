n=input()
l=[]
for i in xrange(n):
	l.append(map(int,raw_input().split()))
if(n>2):
	x=(l[0][1]+l[0][2]-l[1][2])/2
	s=str(x)
	for i in l[0]:
		if i==0:
			continue
		else:
			s+=" "+str(i-x)
else:
	x=l[0][1]/2
	s=str(x)+" "+str(x)
print s		
