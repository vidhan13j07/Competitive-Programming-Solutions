#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pop pop_back
#define li(v,it) for(int it=0;it<sc(v);it++)
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int n,temp;
	cin>>n;
	ll ar[1000001]={0};
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		ar[temp]++;
	}
	for(int i=1;i<1000001;i++)	
		while(ar[i]--)
			cout<<i<<endl;
	return 0;
}