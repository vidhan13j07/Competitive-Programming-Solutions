#include<stdio.h>
#include<math.h>
int main()
{
	int X;
	float Y,res;
	scanf("%d %f",&X,&Y);
	if(X>0 && X<=2000 && Y>=0.0 && Y<=2000.0)
	{
		res=Y;
		if(X%5==0)
		{
			res=Y-1.0*X-0.5;
			if(res<0)
				res=Y;
		}
		printf("%0.2f \n",res);
	}
	return 0;
}
