t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	temp=n
	i=1
	while temp-i>0:
		temp-=i
		i+=1
	if i%2==1 and i!=1:
		print "TERM %d IS %d/%d" %(n,i+1-temp,temp)
	else:
		print "TERM %d IS %d/%d" %(n,temp,i+1-temp)