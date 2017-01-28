def count(n,p):
    k=0
    while n>=p:
        k+=n/p
        n/=p
    return k
def power(y):
    x=1
    b=m-2
    while(b>0):
        if(b%2==1):
            x=(x*y)
            if(x>m):
            	x%=m
        y = (y*y)
        if(y>m):
        	y%=m 
        b /= 2
    return x
def InverseEuler(n):
    return power(n)
def cal(n,r):
	if count(n,m)>count(r,m)+count(n-r,m):
		return 0
	else:
		return (factMOD(n)*((InverseEuler(factMOD(r))*InverseEuler(factMOD(n-r)))%m))%m
def factMOD(n):
    res=1
    while n>0:
    	k=n%m
        res*=l[k]
        #print k,res
        n=n/m
        if n%2>0: 
            res=m-res;
    return res
l=[1]
s=1
m=10**6+3
for i in xrange(1,10**6+3):
	s=(s*i)%m
	l.append(s)
t=int(raw_input())
while t>0:
	t-=1
	n,le,r=map(int,raw_input().split())
	k=r-le+1
	ans=cal(n+k,n)-1
	while ans<0:
		ans+=m
	print ans
