n=int(raw_input())
l=map(int,raw_input().split())
l1=[0 for x in xrange(n)]
a=list(set(l))
a.sort()
a=a[::-1]
k=1
for i in a:
    count=0
    for j in xrange(n):
        if l[j]==i:
            count+=1
            l1[j]=k
    k+=count
for i in l1:
    print i,
print