#include<stdio.h>
#define m 1000000007
#define ull unsigned long long int
#define s scanf
#define p printf
#define min(a,b) a<b?a:b
int main()
{
	int ar[10001],t,n,i,j;
	for(i=1;i<10001;i++)
		ar[i]=i;
	for(i=2;i<10001;i++)
		for(j=i+i;j<10001;j+=i)
			ar[j]/=ar[i];
	ull arr[10001];
	arr[1]=1;
	for(i=2;i<10001;i++)
		arr[i]=(arr[i-1]*ar[i])%m;
	s("%d",&t);
	while(t--)
	{
		s("%d",&n);
		p("%lld\n",arr[n]);
	}
	return 0;
}