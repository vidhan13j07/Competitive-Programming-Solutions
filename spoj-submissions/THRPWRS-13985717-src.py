while 1:
	n=int(raw_input())
	if n==0:
		break
	k=1
	n-=1
	l=bin(n)
	s=[]
	l=l[2:]
	l=l[::-1]
	for i in l:
		if i=='1':
			s.append(str(k))
		k*=3
	s=", ".join(s)
	print "{ "+s+" }"
	#{ 59049, 3486784401, 205891132094649, 717897987691852588770249 }