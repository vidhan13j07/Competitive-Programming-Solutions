t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	s=n/2048
	n%=2048
	s+=list(bin(n)).count('1')
	print s
