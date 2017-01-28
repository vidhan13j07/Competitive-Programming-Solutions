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
const int N=505;
const int N1=1e5+5;
bool vis[N][N];
int ans[N1];
int main() 
{
    int x,y,x0,y0;
    string s;
    cin>>x>>y>>x0>>y0>>s;
    f(i,0,N)
        f(j,0,N)
            vis[i][j]=0;
    vis[x0][y0]=1;
    int cnt=1,l=sc(s);
    ans[0]=cnt;
    f(i,0,l)
    {
        int a=x0,b=y0;
        if(s[i]=='D')
            a++;
        else if(s[i]=='U')
            a--;
        else if(s[i]=='L')
            b--;
        else
            b++;
        if(a<1 or a>x or b<1 or b>y)
        {
            a=x0;
            b=y0;
        }
        x0=a;
        y0=b;
        if(vis[a][b])
        {
            if(i+1==l)
                ans[i+1]=x*y-cnt;
            else
                ans[i+1]=0;
        }
        else
        {
            cnt++;
            vis[a][b]=1;
            if(i+1==l)
                ans[i+1]=x*y-cnt+1;
            else
                ans[i+1]=1;
        }
    }
    f(i,0,l+1)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}