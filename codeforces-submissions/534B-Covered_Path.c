#include<stdio.h>
#include<math.h>
int main()
{
	int init,final,n,d,i,j,temp,dist,tempp;
	scanf("%d%d",&init,&final);
	scanf("%d%d",&n,&d);
	i=1;
	tempp=init;
	dist=init;
	while(1)
	{
		i++;
		dist+=tempp+d;
		tempp+=d;
		if(abs(tempp-final)>(n-i)*d)
		{
			dist-=tempp;
			dist+=final+(n-i)*d;
			tempp=final+(n-i)*d;
			break;
		}
		else if(i>=n)
			break;
	}
	tempp-=d;
	for(j=i;j<n;j++)
	{
		dist+=tempp;
		tempp-=d;
	}
	printf("%d\n",dist);
	return 0;
}
