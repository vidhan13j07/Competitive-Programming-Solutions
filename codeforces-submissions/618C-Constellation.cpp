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

const int N=1e5+5;
pair< pi , int > p[N];
set<int> st;
vi ans;
ll are(pair< pi , int > a,pair< pi , int > b,pair< pi , int > c)
{
	return (((ll)a.first.first*((ll)b.fi.se-(ll)c.fi.se))+((ll)b.fi.fi*((ll)c.fi.se-(ll)a.fi.se))+((ll)c.fi.fi*((ll)a.fi.se-(ll)b.fi.se)));
}
bool cmp(pair< pi , int >& a,pair< pi , int >& b)
{
	if(a.fi.fi!=b.fi.fi)
		return a.fi.fi<b.fi.fi;
	return a.fi.se<=b.fi.se;
}
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
    int n;
    scanf("%d",&n);
    f(i,0,n)
    {
    	scanf("%d %d",&p[i].fi.fi,&p[i].fi.se);
    	p[i].se=i;
    	st.insert(p[i].fi.fi);
    }
    sort(p,p+n,cmp);
    int i=0;
    while(i<n)
    {
    	if(i+1<n and p[i].fi.fi!=p[i+1].fi.fi and are(p[i],p[i+1],p[i+2])!=0)
    	{
    		ans.eb(p[i].se);
    		ans.eb(p[i+1].se);
    		ans.eb(p[i+2].se);
    		break;
    	}
    	if(i+1<n and p[i].fi.fi==p[i+1].fi.fi)
    	{
    		int j=i+2;
    		while(j<n and p[j].fi.fi==p[i].fi.fi and are(p[i],p[i+1],p[j])==0)
    			j++;
    		if(j!=n)
    		{
    			ans.eb(p[i].se);
    			ans.eb(p[i+1].se);
    			ans.eb(p[j].se);
    			break;
    		}
    	}
    	i++;
    }
    for(auto i:ans)
    	cout<<i+1<<" ";
    cout<<endl;
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}