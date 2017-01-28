#include <stdio.h>
#include <math.h> 
int main()
{
 
	int n;
	double min=999999999;
	double max=0;
	int minans;
	int maxans;
	int index = 1;
	double sum;
	double area;
	int x1,x2,x3,y1,y2,y3;
	double side1,side2,side3;
	scanf("%d",&n);
 
	while(n--)
	{
		scanf("%d %d %d %d %d %d",&x1, &y1, &x2, &y2, &x3, &y3);
 
		side1 = sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
		side2 = sqrt( pow((x3-x1),2) + pow((y3-y1),2) );
		side3 = sqrt( pow((x3-x2),2) + pow((y3-y2),2) );
 
		sum = (side1+side2+side3)/2.0;
 
		area = sqrt(sum * (sum-side1) * (sum-side2) * (sum-side3) );
 
		if (area <= min)
		{
			min = area;
			minans = index;
		}
 
		if(area >= max)
		{
			max = area;
			maxans = index;
		}
 
		index++;
	}
 
	printf("%d %d\n",minans, maxans);
	return 0;
 
}
