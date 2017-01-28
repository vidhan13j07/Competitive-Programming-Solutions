from math import factorial
n,m=map(int,raw_input().split())
l=[int(x) for x in raw_input().split()]
s=0
for i in l:
	f=(factorial(i+1)-1)+(i*i*(i+1))/2
	s+=(f%m)
print s%m
