t=input()
while t>0:
	t-=1
	x,y=map(int,raw_input().split())
	if(x<=1 and y==x):
		ans=x
	elif(y==x):
		if(x%2==0):
			ans=2*x
		else:
			ans=2*x-1
	elif(y+2==x):
		if(y%2==0):
			ans=2*y+2
		else:
			ans=2*y+1
	else:
		print "No Number"
		continue
	print ans
