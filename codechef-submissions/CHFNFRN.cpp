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
 
const int N = 1e3 + 5;
bool fl[N][N], vis[N], ans;
vi v[2];
void dfs(int i, int mask, int n) {
    for(auto it: v[mask])
        if(!fl[it][i])
            ans = 0;
    v[mask].eb(i);
    vis[i] = 1;
    f(j,0,n)
        if(!vis[j] and !fl[i][j])
            dfs(j, (mask^1), n);
}
int main()
{
    TC() {
        v[0].clear();
        v[1].clear();
        memset(fl, 0, sizeof fl);
        memset(vis, 0, sizeof vis);
        int n, m;
        scanf("%d %d",&n, &m);
        while(m--) {
            int a, b;
            scanf("%d %d",&a, &b);
            if(a == b)
                continue;
            a--;
            b--;
            fl[a][b] = fl[b][a] = 1;
        }
        ans = 1;
        f(i,0,n)
            if(!vis[i])
                dfs(i, 0, n);
        printf(ans?"YES\n":"NO\n");
    }
    return 0;
}
