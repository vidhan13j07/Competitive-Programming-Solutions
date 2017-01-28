#include<stdio.h>
#include<math.h>
int main()
{
	int t,d;
	unsigned long long int k,m;
	double x,ans;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%lf %lld",&x,&k);
		ans=x/2;
		m=2;
		k--;
		while(k!=0)
		{
			d=k-m;
			if(d<=0)
			{
				ans=x*((2*k)-1)/(2*m);
				break;
			}
			k-=m;
			m*=2;
		}
		printf("%f\n",ans);
	}
	return 0;
}
