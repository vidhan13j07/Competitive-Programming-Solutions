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
vi ar(N,0);
bool pal(int n)
{
	int p[6],i=0;
	while(n)
	{
		p[i++]=n%10;
		n/=10;
	}
	f(j,0,i)
		if(p[j]!=p[i-j-1])
			return 0;
	return 1;
}
int main() 
{
	int l,r;
	f(i,1,N)
		ar[i]=pal(i)?i:0;
	f(i,0,N-1)
		ar[i+1]+=ar[i];
	TC()
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",ar[r]-ar[l-1]);
	}
	return 0;
}
