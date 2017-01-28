t = int(raw_input())
i = 0
while i < t:
	i += 1
	x1,y1,x2,y2,ac,l = map(float,raw_input().split())
	ab = ((x1-x2)**2+(y1-y2)**2)**0.5
	bc = l/2**0.5
	cosa = (ab**2+ac**2-bc**2)/(2*ab*ac)
	if cosa <= 1:
		ans = 2*ac*((1-cosa**2)**0.5)
		print "%d. %.3f" % (i,ans)
	else:
		print "%d. No problem" % (i)