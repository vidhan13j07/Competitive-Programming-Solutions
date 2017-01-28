def quicksort(a,b,first,last):
	if(first<last):
		pivot=first
		i=first
		j=last
		while i<j:
			while a[i]<=a[pivot] and i<last:
				i+=1
			while a[j]>a[pivot]:
				j-=1
			if i<j:
				temp=a[i]
				a[i]=a[j]
				a[j]=temp
				temp=b[i]
				b[i]=b[j]
				b[j]=temp
		temp=a[pivot]
		a[pivot]=a[j]
		a[j]=temp
		temp=b[pivot]
		b[pivot]=b[j]
		b[j]=temp
		quicksort(a,b,first,j-1)
		quicksort(a,b,j+1,last)
t=int(raw_input())
while t>0:
	t-=1
	n=int(raw_input())
	l=[]
	r=[]
	for i in xrange(n):
		a=raw_input().split()
		l.append(int(a[0]))
		r.append(int(a[1]))
	quicksort(r,l,0,n-1)
	s=0
	i=0
	while i<n:
		j=i
		c=0
		while j<n:
			if l[j]<=r[i]:
				c+=1
				j+=1
			else:
				break
		if c>0:
			s+=1
		i=j
	print s
