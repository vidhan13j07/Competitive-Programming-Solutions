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
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int ar[105];
	int t,n,s,temp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		f(i,1,101)
			ar[i]=0;
		f(i,0,n)
		{
			cin>>temp;
			ar[temp]++;
		}
		s=0;
		f(i,1,101)
			if(ar[i])
				s++;
		cout<<s<<endl;
	}
	return 0;
}
