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

const int N=505;
bool vis[N],mat[N][N];
char ans[N];
vi v[N],done,d;
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
    int n,m,a,b;
    bool ok = 1;
    cin>>n>>m;
    f(i,0,n)
    {
    	vis[i]=1;
    	ans[i]='b';
    }
    f(i,0,n)
    	f(j,0,n)
    		mat[i][j]=0;
    while(m--)
    {
    	cin>>a>>b;
    	a--;b--;
    	mat[a][b]=mat[b][a]=1;
    }
    f(i,0,n)
    	f(j,i+1,n)
    		if(!mat[i][j])
    		{
    			v[i].eb(j);
    			v[j].eb(i);
    		}
    f(i,0,n)
    	if(sc(v[i])>0)
    	{
    		for(auto it:done)
    			if(!mat[i][it])
    			{
    				vis[i]=0;
    				break;
    			}
    		if(vis[i])
    		{
    			ans[i]='a';
    			done.eb(i);
    			continue;
    		}
    		vis[i]=1;
    		for(auto it:d)
    		{
    			if(!mat[i][it])
    			{
    				vis[i]=0;
    				break;
    			}
    		}
    		if(vis[i])
    		{
    			d.eb(i);
    			ans[i]='c';
    			continue;
    		}
    		ok = 0;
    		break;
    	}
    f(i,0,n)
    	f(j,i+1,n)
    		if(ans[i]==ans[j] or abs(ans[i]-ans[j])==1)
    		{
    			if(!mat[i][j])
    				ok=0;
    		}
    		else if(mat[i][j])
    			ok=0;
    if(!ok)
    	printf("No\n");
    else
    {
    	printf("Yes\n");
    	f(i,0,n)
    		printf("%c",ans[i]);
    	printf("\n");
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}