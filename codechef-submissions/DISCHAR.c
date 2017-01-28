#include<stdio.h>
int main()
{
        int t,i,c,k;
        scanf("%d",&t);
        int ar[26];
        for(;t>0;t--)
        {
                c=0;
                char a[100005];
                scanf("%s",a);
                for(i=0;i<26;i++)
                        ar[i]=0;
                for(i=0;a[i]!='\0';i++)
                {
                        k=(int)a[i];
                        k=k-97;
                        ar[k]=1;
                }
                for(i=0;i<26;i++)
                        if(ar[i]>0)
                                c++;
                printf("%d\n",c);
        }
        return 0;
}
