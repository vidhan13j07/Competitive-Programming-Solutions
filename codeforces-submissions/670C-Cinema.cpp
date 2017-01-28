#include<bits/stdc++.h>
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define mk make_pair
#define fi first
#define se second
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main()
{
	int n,m;
	cin>>n;
	int ar[n];
	f(i,0,n)
		cin>>ar[i];
	map<int,int> mp;
	f(i,0,n)
		mp[ar[i]]++;
	cin>>m;
	int b[m],c[m];
	f(i,0,m)
		cin>>b[i];
	f(i,0,m)
		cin>>c[i];
	int x[m],y[m];
	f(i,0,m)
		x[i] = y[i] = 0;
	f(i,0,m)
	{
		x[i] = mp[b[i]];
		y[i] = mp[c[i]];
	}
	int ma1 = 0,ind = 0,ma2 = 0;
	f(i,0,m)
		if(ma1 < x[i])
		{
			ma1 = x[i];
			ma2 = y[i];
			ind = i;
		}
		else if(ma1 == x[i] && ma2 < y[i])
		{
			ind = i;
			ma2 = y[i];
		}
	cout<<(ind + 1)<<endl;
    return 0;
}
