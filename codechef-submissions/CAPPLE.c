#include<stdio.h>
int n;
void quicksort(int[] ,int,int);
int main()
{
	int t,c,n,temp,pos,i;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d",&n);
		unsigned int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		/*for(i=0;i<n;i++)
		{
			pos=i;
			for(j=i+1;j<n;j++)
				if(a[j]>a[pos])
					pos=j;
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}*/
		quicksort(a,0,n-1);
		c=1;
		for(i=1;i<n;i++)
			if(a[i]!=a[i-1])
				c++;
		printf("%d\n",c);
	}
	return 0;
}
void quicksort(int x[n],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
         pivot=first;
         i=first;
         j=last;
         while(i<j)
    	 {
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j)
             {
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);
    }
}
