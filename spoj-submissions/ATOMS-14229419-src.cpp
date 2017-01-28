#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
	long long n,k,m,pro;    
	int t,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
       	ans=0;
        if(k <= m/n)
        {
           ans++;
           pro = n*k;
           while( k <= m/pro)
           {
               ans++;
               pro *= k;
           }
       }
        printf("%i\n",ans);
    }
	return 0;
}