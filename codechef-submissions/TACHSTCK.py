n,d=map(int,raw_input().split())
l,s,i=[],0,1
for _ in xrange(n):
	l.append(int(raw_input()))
l.sort()
while i<n:
	if l[i]-l[i-1]<=d:
		s+=1
		i+=2
	else:
		i+=1
print s
