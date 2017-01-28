t=int(raw_input())
while t>0:
	t-=1
	j=raw_input()
	s=raw_input()
	k=(set(j) & set(s))
	ans=0
	for i in k:
		ans+=s.count(i)
	print ans
