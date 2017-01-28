#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,e,n,ans;
	cin>>t;
	while(t--)
	{
		cin>>e>>n;
		ans=0;
		while((e>=1 and n>=2) or (e>=2 and n>=1))
		{
			if(e>n)
			{
				n-=1;
				e-=2;
			}
			else
			{
				n-=2;
				e-=1;
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}