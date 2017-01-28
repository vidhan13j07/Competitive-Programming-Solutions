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

const int N=105;
int root[N],ar[N],size[N];
vi v[N];
int find_root(int i)
{
    while(i!=root[i])
        i=root[i];
    return i;
}
void add(int i,int j)
{
    int x=find_root(i);
    int y=find_root(j);
    if(x==y)
        return ;
    if(size[x]<size[y])
    {
        size[y]+=size[x];
        root[x]=y;
    }
    else
    {
        size[x]+=size[y];
        root[y]=x;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
    int n,m,ch,k,ans=0;
    scanf("%d %d",&n,&m);
    f(i,0,n)
    {
        size[i]=1;
        root[i]=i;
    }
    bool fl=0;
    f(i,0,n)
    {
        scanf("%d",&ch);
        if(ch>0)
            fl=1;
        f(j,0,ch)
        {
            scanf("%d",&k);
            v[k].eb(i);     
        }
    }
    if(!fl)
    {
        cout<<n<<endl;
        return 0;
    }
    f(i,1,m+1)
    {
        if(sc(v[i])<=1)
            continue;
        f(j,1,sc(v[i]))
            add(v[i][j],v[i][j-1]);
    }
    f(i,0,n)
        if(find_root(i)==i)
            ans++;
    ans--;
    printf("%d\n",ans);
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
