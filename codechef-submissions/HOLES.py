t=int(raw_input())
while t>0:
	t-=1
	s=raw_input()
	n=0
	for i in s:
		if i=='A' or i=='D' or i=='O' or i=='P' or i=='R' or i=='Q':
			n+=1
		elif i=='B':
			n+=2
	print n
