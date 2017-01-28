#include<stdio.h>
int main()
{
int i,j,p[104730],in=1,n[1500000]={0};
p[1]=2;
for(i=3;i<=1224;i+=2)
if(n[i]==0)
{
p[++in]=i;
for(j=i*i;j<=1500000;j+=2*i)n[j]=1;
}
for(;i<=1500000;i+=2)if(n[i]==0)p[++in]=i;
for(i=1;i<=10000;i++)printf("%d ",p[p[i]]);
return 0;
}