n=int(raw_input())
l=[]
while n>0:
	n-=1
	l.append(raw_input())
l1=list(set(l))
for i in sorted(l1):
	print i+" "+str(l.count(i))
