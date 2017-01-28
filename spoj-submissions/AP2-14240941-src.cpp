#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() 
{
	int t;
	ll a,b,s,n,d,x;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>s;
		n=2*s/(a+b);
		d=(a-b)/(5-n);
		x=a-2*d;
		cout<<n<<"\n";
		for(int i=0;i<n;i++)
			cout<<x+i*d<<" ";
		cout<<endl;
	}
	return 0;
}