#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    int ar[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&ar[i][j]);
    int ar1[n];
    for(int i=0;i<n;i++)
        ar1[i]=1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(ar[i][j]==1)
                ar1[i]=0;
            else if(ar[i][j]==2)
                ar1[j]=0;
            else if(ar[i][j]==3)
            {
                ar1[i]=0;
                ar1[j]=0;
            }
        }
    for(int i=0;i<n;i++)
        if(ar1[i]==1)
            ans++;
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
        if(ar1[i]==1)
            printf("%d ",i+1);
    printf("\n");
    return 0;
}