/*The Best Box*/
 
#include<stdio.h>
#include<math.h>
 
int main()
{
	int i,t;
	long int P,S;
	float b,v;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld %ld",&P,&S);
		b=(P-(float)sqrt((float)(P*P-24*S)))/12;
		v=b*(S/2-P*b/4+b*b);
		printf("%.2f\n",v);
	}
	return 0;
}
