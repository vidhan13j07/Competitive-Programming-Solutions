while(1):
	a1,a2,a3=map(int,raw_input().split())
	if(a1==a2 and a2==a3 and a1==0):
		break
	if(a2-a1==a3-a2):
		print "AP %d" %(a3+(a3-a2))
	else:
		print "GP %d" %(a3*float(a3/a2))
