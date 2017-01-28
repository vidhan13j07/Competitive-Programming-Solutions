#include<stdio.h>
int main()
{
int t,M,i,j,k;
scanf("%d %d",&t,&M);
k=0;
int ar[t][t];
for(i=0;i<t;i++)
for(j=0;j<t;j++)
{
scanf("%d",&ar[i][j]);
if(ar[i][j]==M)						
k=1;
}
if(k==1)
printf("YES\n");
else
printf("NO\n");
return 0;
}
