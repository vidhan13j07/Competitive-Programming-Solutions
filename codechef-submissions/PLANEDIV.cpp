#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define fi first
#define se second 
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;
const int N=1e5+5;
map< double , set<double> > mp;
int main() 
{
	int n,ma;
	double x,y,z;
	TC()
	{
		set<double> s;
		mp.clear();
		cin>>n;
		f(i,0,n)
		{
			cin>>x>>y>>z;
			if(y!=0)
			{
				x/=y;
				z/=y;
				//cout<<x<<" "<<z<<endl;
				mp[x].insert(z);
			}
			else
			{
				z/=x;
				s.insert(z);
			}
		}
		ma=sc(s);
		for(auto i:mp)
			if(sc(i.se)>ma)
				ma=sc(i.se);
		cout<<ma<<endl;
	}
	return 0;
}
