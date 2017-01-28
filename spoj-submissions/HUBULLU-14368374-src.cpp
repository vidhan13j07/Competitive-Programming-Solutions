#include <iostream>
#include<bits/stdc++.h>
#include<map>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
using namespace std;
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==0)
			cout<<"Airborne wins."<<endl;
		else
			cout<<"Pagfloyd wins."<<endl;
	}
	return 0;
}