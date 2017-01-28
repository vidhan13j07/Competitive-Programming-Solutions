n=input()
l=[n]
flag=0
while n>1 and flag==0:
	if n%2==0:
		n=n/2
	else:
		n=3*n+3
	for i in l:
		if n==i:
			flag=1
			break
	else:
		l.append(n)
if flag==1:
	print "NIE"
else:
	print "TAK"
