t=input()
while t>0:
	t-=1
	c1,c2=map(int,raw_input().split())
	if c1%2==1 and c2%2==1:
		print "Ramesh"
	else:
		print "Suresh"
