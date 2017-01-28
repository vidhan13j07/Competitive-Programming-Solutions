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

const int N = 2e3 + 5;
pi p[N];
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    clock_t tStart = clock();
    int n;
    scanf("%d",&n);
    f(i,0,n)
        scanf("%d %d",&p[i].fi, &p[i].se);
    int ans = 0;
    f(i,0,n) {
        map< pi,int > mp;
        f(j,i + 1, n) {
            int xx = p[i].fi - p[j].fi;
            int yy = p[i].se - p[j].se;
            int g = __gcd(xx, yy);
            xx /= g;
            yy /= g;
            if(mp.find(mk(-xx, -yy)) != mp.end())
                mp[mk(-xx, -yy)] += 1;
            else
                mp[mk(xx, yy)] += 1;
        }
        int s = 0, k = 0;
        for(auto it: mp)
            s += it.se;
        for(auto it: mp) {
            k += it.se;
            ans += it.se*(s - k);
        }
    }
    printf("%d\n", ans);
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


