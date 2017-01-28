#include<stdio.h>
#include<string.h>
int main()
{
	int t,l,j,c,i;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		char a[100000];
		scanf("%s",a);
		l=strlen(a);
		c=0;
		j=l-1;
		for(i=0;i<(l/2) && i<j;i++,j--)
		{
			if(a[i]==a[j])
				continue;
			else if(a[i]==a[j-1])
			{
				j--;
				c++;
			}
			else if(a[i+1]==a[j])
			{
				i++;
				c++;
			}
			else
				c=2;
		}
		if(c==1 || c==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
