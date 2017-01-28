def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)
t=int(raw_input())
for _ in xrange(1,t+1):
	s='Case '+str(_)+': '
	a,b,c=map(int,raw_input().split())
	#6x+12y=3
	#2x+4y=1
	if c%gcd(a,b)==0:
		print s+'Yes'
	else:
		print s+'No'