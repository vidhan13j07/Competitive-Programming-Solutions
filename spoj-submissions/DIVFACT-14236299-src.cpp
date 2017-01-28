#include<iostream>
#include<bits/stdc++.h>
#define m 1000000007
#define ll long long int
using namespace std;
int prime[5134],ind=1,number[50000]={0};
int main()
{
    int i,j,t; 
    prime[1] = 2;
    for(i=3;i<=223;i += 2)
    {
        if(number[i] == 0)
        {
            prime[++ind] = i;
            for(j=i*i;j<=50000;j+=2*i)
                number[j]=1;
        }
    }
    for(;i<50000;i+=2)
        if(number[i]==0)
            prime[++ind] = i;
    cin>>t;
    ll ans,power,k,n;
    while(t--)
    {
    	cin>>n;
    	ans=1;
    	for(i=1;prime[i]<=n and i<=ind;i++)
    	{
    		power=0;k=prime[i];
    		while(n/k)
    		{
    			power+=n/k;
    			k*=prime[i];
    		}
    		ans=(ans*(power+1))%m;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}