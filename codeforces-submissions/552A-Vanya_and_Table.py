n=int(raw_input())
s=0
while n>0:
    n-=1
    x0,y0,x1,y1=map(int,raw_input().split())
    s+=(x1-x0+1)*(y1-y0+1)
print s