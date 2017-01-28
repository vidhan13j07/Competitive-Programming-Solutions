#include<stdio.h>
int main()
{
	int t,i,pos,j;
	char a[1005];
	scanf("%d",&t);
	int ar[26];
	char ch;
	for(;t>0;t--)
	{
		scanf("%s",a);
		for(i=0;i<26;i++)
			ar[i]=0;
		for(i=0;a[i]!='\0';i++)
		{
			j=(int)a[i];
			j=j-97;
			ar[j]++;
		}
		pos=0;
		for(i=1;i<26;i++)
			if(ar[i]>ar[pos])
				pos=i;
		ch=(char)(pos+97);
		for(i=0;a[i]!='\0';i++)
			if(ch==a[i])
				printf("?");
			else
				printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}
