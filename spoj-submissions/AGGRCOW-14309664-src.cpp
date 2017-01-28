#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define vi(i) vector <int> i
#define vl(i) vector <ll> i
#define vst(i) vector <string> i
#define sc(v) v.size()
#define eb emplace_back
#define pop pop_back
#define li(v,it) for(int it=0;it<sc(v);it++)
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define for(i,a,b) for(int i=a;i<b;i++)
using namespace std;
vector <ll> v;
int n;
bool cal(ll mid,int k)
{
	ll start=v[0];
	k--;
	int i=1;
	while(k and i<n)
	{
		if((v[i]-start)>=mid)
		{
			start=v[i];
			k--;
		}
		i++;
	}
	if(k)
		return false;
	else
		return true;
}
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,k;
	ll temp,start,end,mid;
	cin>>t;
	while(t--)
	{
		v.clear();
		cin>>n>>k;
		for(i,0,n)
		{
			cin>>temp;
			v.eb(temp);
		}
		sort(v.begin(),v.end());
		start=0,end=v[n-1];
		while(start<end)
		{
			mid=(start+end)/2;
			if(cal(mid,k))
				start=mid+1;
			else
				end=mid;
		}
		cout<<start-1<<endl;
	}
	return 0;
}