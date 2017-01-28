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
#define endl "\n"
#define eps 1e-9
#define pw(x) (1ll<<(x))
#define trace1(x)                cout <<#x<<": "<<x<<endl;
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

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

const int N = 1e5 + 5;
vi v[N];
int sz = 1, c[N], z[N];
void edge(int i,int j)
{
	v[i].eb(j);
	v[j].eb(i);
}
int check()
{
	int i = 0;
	if(!v[0].empty())
	{
		if(sc(v[v[0][0]]) > 1)
			i = v[0][0];
	}
	return i;
}
void dfs(int e = 0,int p = -1)
{
	vi a;
	for(auto it: v[e])
		if(p != it)
		{
			dfs(it, e);
			a.eb(c[it] + 1);
			c[e] = max(c[e],a.back());
		}
	z[e] = c[e];
	if(a.empty())
		return ;
	sort(a.rbegin(), a.rend());
    if (a.size() > 1)
        z[e] = a[0] + a[1];
}
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
	int n,d,h;
	cin>>n>>d>>h;
	f(i,0,h)
	{
		edge(i,sz);
		sz++;
	}
	for(int i = 0, j = h, hg = 0;j < d and hg < h;j++, hg++)
	{
		edge(i,sz);
		i = sz;
		sz++;
	}
	int start = check();
	while(sz < n)
	{
		edge(start, sz);
		sz++;
	}
	dfs();
	if (n != sz or c[0] != h or z[0] != d)
	{
        printf("-1");
        return 0;
    }
    f(i,0,n)
    	for(auto j: v[i])
    		if(i < j)
    			printf("%d %d\n",i + 1, j + 1);
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
