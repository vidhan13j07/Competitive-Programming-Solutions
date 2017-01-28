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
const ll mod = 1e9 + 7;
ll a[N], b[N], fact[5*N], ma[4*N], mi[4*N];
ll power(ll a, ll b) {
    ll x = 1;
    while(b) {
        if(b&1)
            x *= a;
        a *= a;
        if(x >= mod)
            x %= mod;
        if(a >= mod)
            a %= mod;
        b >>= 1;
    }
    return x;
}
ll inv_power(ll x) {
    return power(x, mod - 2);
}
ll ncr(ll a, ll b) {
    if(b > a)
        return 0;
    ll x = fact[a]*inv_power(fact[b]);
    if(x >= mod)
        x %= mod;
    x *= inv_power(fact[a - b]);
    if(x >= mod)
        x %= mod;
    return x;
}
ll catalan(ll n, ll k) {
    ll x1 = ncr(n + k, k);
    ll x2 = ncr(n + k, k - 1);
    x1 -= x2;
    while(x1 < 0)
        x1 += mod;
    if(x1 >= mod)
        x1 %= mod;
    return x1;
}
void build(int node, int i, int j) {
    if(i > j)
        return;
    if(i == j) {
        ma[node] = a[i];
        mi[node] = b[i];
        return;
    }
    int mid = (i + j)/2;
    build(2*node + 1, i, mid);
    build(2*node + 2, mid + 1, j);
    ma[node] = max(ma[2*node + 1], ma[2*node + 2]);
    mi[node] = min(mi[2*node + 1], mi[2*node + 2]);
}
pair<ll,ll> query(int node, int i, int j, int l, int r) {
    if(i > j or i > r or j < l)
        return {0,5*N};
    if(i >= l and j <= r)
        return {ma[node], mi[node]};
    int mid = (i + j)/2;
    pair<ll,ll> x1 = query(2*node + 1, i, mid, l, r);
    pair<ll,ll> x2 = query(2*node + 2, mid + 1, j, l, r);
    return {max(x1.fi,x2.fi), min(x1.se,x2.se)};
}
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
    fact[0] = 1;
    for(ll i = 1;i < 5*N;i++) {
        fact[i] = fact[i - 1]*i;
        if(fact[i] >= mod)
            fact[i] %= mod;
    }
    int n, q;
    scanf("%d %d",&n, &q);
    f(i,0,n) {
        scanf("%lld", a+i);
        a[i] /= 2;
    }
    f(i,0,n)
        scanf("%lld", b+i);
    build(0, 0, n - 1);
    //f(i,0,30)
    //	trace3(i, ma[i], mi[i]);
    while(q--) {
        int c, d;
        scanf("%d %d",&c, &d);
        c--;
        d--;
        pair<ll,ll> p = query(0, 0, n - 1, c, d);
        //trace2(p.fi,p.se);
        if(p.se > p.fi) {
            printf("0\n");
            continue;
        }
        ll ans = catalan(p.fi - 1, p.fi - p.se);
        printf("%lld\n", ans);
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
