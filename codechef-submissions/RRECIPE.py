t=int(raw_input())
while t>0:
	t-=1
	s=[x for x in raw_input()]
	l=len(s)
	ans=1
	for i in xrange((l+1)//2):
		if s[i]==s[l-i-1]:
			if s[i]=='?':
				ans=(ans*26)%(10**7+9)
		else:
			if s[i]!='?' and s[l-i-1]!='?':
				ans=0
				break
	print ans%10000009
