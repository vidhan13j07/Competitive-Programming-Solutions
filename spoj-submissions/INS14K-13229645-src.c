#include<stdio.h>
int main()
{
	int t,n,i,q,temp,c;
	int x1[2000],x2[2000],y1[2000],y2[2000];
	float pos;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
		scanf("%d",&q);
		for(;q>0;q--)
		{
			scanf("%d",&temp);
			if(temp==0)
			{
				c=0;
				scanf("%f",&pos);
				for(i=0;i<n;i++)
				if(x1[i]<=pos && x2[i]>=pos)
						c++;
				printf("%d\n",c);
			}
			else
			{
				scanf("%d %d %d %d",&x1[n],&y1[n],&x2[n],&y2[n]);
				n++;
			}
		}
	}
	return 0;
}			
