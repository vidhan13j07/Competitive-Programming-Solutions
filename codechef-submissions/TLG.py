n=int(raw_input())
sa,sb,pl,ans=0,0,1,0
while n>0:
	n-=1
	a,b=map(int,raw_input().split())
	sa+=a
	sb+=b
	if abs(sa-sb)>ans:
		ans=abs(sa-sb)
		if sa>sb:
			pl=1
		else:
			pl=2
print str(pl)+" "+str(ans)
