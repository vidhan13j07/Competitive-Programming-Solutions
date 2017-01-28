t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	print "BOB" if n%2==1 else "ALICE"
