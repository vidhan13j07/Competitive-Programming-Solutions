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

const int N = 1024;
int main()
{
	int n, t, ans = 1;
	scanf("%d %d",&n,&t);
	if(t == 0) {
		cout<<"0\n";
		return 0;
	}
	ll x[n + 1][n + 1];
	f(i,0,n + 1)
		f(j,0,n + 1)
			x[i][j] = 0;
	x[1][1] = (ll)(N * (t - 1));
	f(i,2,n + 1)
		f(j,1,i + 1) {
			x[i][j] = (x[i - 1][j] >> 1) + (x[i - 1][j - 1] >> 1);
			if(x[i][j] >= N) {
				ans++;
				x[i][j] -= N;
			}
			else
				x[i][j] = 0;
			//trace4(i,j,x[i][j],ans);
 		}
	printf("%d\n",ans);
    return 0;
}
