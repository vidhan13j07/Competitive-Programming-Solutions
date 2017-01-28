from math import sqrt as sq
i,k,s=map(int,raw_input().split())
a,b=map(float,raw_input().split())
x,z,y=sq(2),sq(3),sq(6)
if k>=i and s>=0:
    temp=k-i
    if temp%2==0:
        temp=2*temp-s
        ans=1.0*(a+b)
    else:
        temp=2*temp-1-s
        ans=1.0*(x*a+y*b)
    ans=(ans*(2**(temp)))
else:
    temp=i-k
    s1=abs(s)
    if temp%2==0:
        s1-=2*temp
        ans=(a+b)
    else:
        s1=s1-2*temp+2
        ans=(1.0*(a+z*b))/(4*x)
    ans=(ans*(2**(s1)))
print "%0.6f" %(ans)
