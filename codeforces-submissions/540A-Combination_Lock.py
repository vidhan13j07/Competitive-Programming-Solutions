n=int(raw_input())
l1=[int(x) for x in raw_input()]
l2=[int(x) for x in raw_input()]
s=0
for i in xrange(n):
    s+=min(abs(l1[i]-l2[i]),9-max(l1[i],l2[i])+min(l1[i],l2[i])+1)
print s
