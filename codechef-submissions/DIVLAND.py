from random import randint
n,m=map(int,raw_input().split())
for _ in xrange(m):
	raw_input()
for i in xrange(2,n-2,2):
	print i+randint(0,1),
print n-2,n-1
