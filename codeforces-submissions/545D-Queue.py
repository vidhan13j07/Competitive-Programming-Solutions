n=int(raw_input())
l=map(int,raw_input().split())
l.sort()
#print l
ans,s=0,0
for i in xrange(n):
    #print l[i],s
    if l[i]>=s:
        ans+=1
        s+=l[i]
print ans