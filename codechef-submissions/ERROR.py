t=int(raw_input())
while t>0:
	t-=1
	s=raw_input()
	if '010' in s or '101' in s:
		print "Good"
	else:
		print "Bad"
