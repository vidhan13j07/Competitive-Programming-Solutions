n=int(raw_input())
l=map(int,raw_input().split())
if (n*(n+1))//2==sum(l):
	print 'YES'
else:
	print 'NO'
