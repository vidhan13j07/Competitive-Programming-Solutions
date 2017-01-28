from math import log
def query(a,b):
	k=int(log(b-a+1,2))
	return max(ar[s[a][k]],ar[s[b-(1<<k)+1][k]])
def build(ar,n):
	s=[[0 for _ in xrange(n)] for __ in xrange(n)]
	for i in xrange(n):
		s[i][0]=i
	j=1
	while 1 << j <=n:
		i=0
		while i + (1 << j) - 1 < n:
			s[i][j]=s[i][j - 1] if (ar[s[i][j - 1]]>ar[s[i+(1<<(j-1))][j-1]]) else s[i+(1<<(j-1))][j-1]
			i+=1
		j+=1
	return s
n=int(raw_input())
ar=map(int,raw_input().split())
m,x,y=map(int,raw_input().split())
s=build(ar,n)
c=0
for _ in xrange(m):
	c+=query(min(x,y),max(x,y))
	x=(x+7)%(n-1)
	y=(y+11)%n
print c
