a,n,k=map(int,raw_input().split())
s=""
while k>0:
	k-=1
	s+=str(a%(n+1))+" "
	a=a/(n+1)
print s
