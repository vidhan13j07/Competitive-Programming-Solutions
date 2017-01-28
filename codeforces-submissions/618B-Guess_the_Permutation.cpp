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

const int N=55;
int ar[N][N],cnt[N];
bool vis[N];
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
    int n;
    cin>>n;
    vi v(n+1);
    f(i,1,n+1)
    {
    	f(j,1,n+1)
    		cin>>ar[i][j];
    	vis[i]=0;
    }
    f(i,1,n+1)
    {
    	f(j,1,n+1)
    		cnt[j]=0;
    	f(j,1,n+1)
    		f(k,1,n+1)
    		{
    			if(j==k)
    				continue;
    			if(ar[j][k]==i)
    			{
    				//trace4(i,j,k,ar[j][k]);
    				cnt[j]++;
    				cnt[k]++;
    			}
    		}
    	//f(j,1,n+1)
    		//trace4(i,j,cnt[j],vis[j]);
    	int ma=0;
    	f(j,1,n+1)
    		ma=max(ma,cnt[j]);
    	f(j,1,n+1)
    		if(ma==cnt[j] and !vis[j])
    		{
    			v[j]=i;
    			vis[j]=1;
    			break;
    		}
    	//cout<<endl;
    }
    f(i,1,n+1)
    	cout<<v[i]<<" ";
    cout<<endl;
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}