def test(W ,M):
    up = 0
    for c in M:
        up = W.find(c,up)
        if(up==-1):
        	return 0
        else:
        	up+=1
    return 1
t=int(raw_input())
while t>0:
	t-=1
	a,b=raw_input().split()
	s='abcdefghijklmnopqrstuvwxyz'
	if len(a)>len(b):
		c=test(a,b)
	else:
		c=test(b,a)
	if c==1:
		print "YES"
	else:
		print "NO"
