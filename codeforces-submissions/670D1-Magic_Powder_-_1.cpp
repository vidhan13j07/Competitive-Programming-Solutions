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

const int N = 1005;
int a[N],b[N];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	f(i,0,n)
		scanf("%d",&a[i]);
	f(i,0,n)
		scanf("%d",&b[i]);
	int ans = 0;
	bool fl = 1;
	while(fl)
	{
		f(i,0,n)
		{
			if(b[i] >= a[i])
				b[i] -= a[i];
			else
			{
				int x = a[i] - b[i];
				b[i] = 0;
				if(k >= x)
					k -= x;
				else
					fl = 0;
			}
		}
		if(fl)
			ans++;
	}
	printf("%d\n",ans);
    return 0;
}