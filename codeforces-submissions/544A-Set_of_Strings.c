#include <stdio.h>
int toint(char c)
{
	return c-'a';
}
int main() 
{
	int k,r[105],n=1,i;
	int ja[30];
	char q[105];
	scanf(" %d",&k);
	scanf("%s",q);
	for(i=0; i<30; i++)
		ja[i] = 0;
	r[0] = 0;
	ja[toint(q[0])] = 1;
	for(i=0; q[i]; i++)
	{
		if(n==k) 
			break;
		if(ja[toint(q[i])])
			continue;
		ja[toint(q[i])] = 1;
		r[n++] = i;
	}
	if(n<k)
	{
		printf("NO\n"); 
		return 0;
	}
	printf("YES");
	n=0;
	for(i=0; q[i]; i++)
	{
		if(i==r[n])
		{
			printf("\n");
			n++;
		}
		printf("%c",q[i]);
	}
	printf("\n");
	return 0;
}
