def power(a,b):
    x=1
    while(b):
        if(b&1):
            x=(x*a)%m
        a=(a*a)%m
        b>>=1
    return x
m=10**9+7
t=int(raw_input())
while t>0:
    t-=1
    n,k=map(int,raw_input().split())
    if k==1:
        print 0
        continue
    inv=power(k-1,m-2)
    inv=power(inv,3)
    inv=(k*inv)%m
    temp=power(k,n)
    n1=(n*n)%m
    t6=(((3*n1)%m+6*n+2)*temp)%m
    t1=(2*((temp*k)%m)*(3*n1+3*n+2))%m
    t2=(((temp*k*k)%m)*(3*n1-1))%m
    temp1=power(k,2*n+1)
    t3=(6*(n+1)*temp1)%m
    t4=(6*k*((n*temp1)%m))%m
    t5=power(k,3*n+2)
    ans=(t6+t5-t4+t3+t2-t1-2*k-2)%m
    ans=(ans*inv)%m
    print ans
