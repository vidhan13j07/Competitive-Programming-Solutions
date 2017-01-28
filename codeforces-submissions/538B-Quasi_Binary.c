#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    char num[10];
    scanf("%s",num);
    int len=strlen(num);
    int m=0;
    for(i=0; i<len ;i++){
        num[i]-='0';
        if(num[i]>m)
        	m=num[i];
    }
    int ans[m][len];
    printf("%d\n",m);
    for(i=0 ; i<m;i++)
        for(j=0 ; j<len;j++)
        	ans[i][j]=0;
    for(i=0;i<len;i++)
    {
        j=0;
        while(num[i])
        {
            ans[j][i]=1;
            num[i]--;
            j++;
        }
    }
    for(i=0 ; i<m;i++)
    {
            int c=0;
        for(j=0;j<len;j++)
        {
           if(ans[i][j] ==0 && c==0);
            else 
            {
                c=1;
                printf("%d",ans[i][j]);
            }
        }
        printf(" ");
    }
    printf("\n");
}

 
