n1,n2,n3=map(int,raw_input().split())
l1,l2,l3=[],[],[]
l1=[int(raw_input()) for i in xrange(n1)]
l2=[int(raw_input()) for i in xrange(n2)]
l3=[int(raw_input()) for i in xrange(n3)]
ans=list((set(l1) & set(l2)) | (set(l1) & set(l3)) | (set(l2) & set(l3)))
print len(ans)
ans.sort()
for i in ans:
	print i
