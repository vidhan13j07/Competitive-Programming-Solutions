#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,m,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int ar[n];
		for(int i=0;i<n;i++)
			cin>>ar[i];
		sort(ar,ar+n);
		ans=0;
		for(int i=0;i<m;i++)
			if(ar[i]<0)
				ans+=(-1*ar[i]);
			else
				break;
		cout<<ans<<endl;
	}
	return 0;
}