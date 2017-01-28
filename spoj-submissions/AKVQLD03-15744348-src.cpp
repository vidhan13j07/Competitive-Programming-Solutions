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
const int N=1<<20+5;
ll val[N];
void update(int i,int b)
{
	for(;i<N;i+=(i&(-i)))
		val[i]+=b;
}
ll query(int a)
{
	ll ans=0;
	for(;a;a-=(a&(-a)))
		ans+=val[a];
	return ans;
}
ll cal(int a,int b)
{
	return query(b)-(a==1?0:query(a-1));
}
int main() 
{
	int n,q,a,b;
	string s;
	f(i,0,N)
		val[i]=0;
	scanf("%d %d",&n,&q);
	while(q--)
	{
		cin>>s;
		scanf("%d %d",&a,&b);
		if(s=="add")
			update(a,b);
		else
			printf("%lld\n",cal(a,b));
	}
	return 0;
}