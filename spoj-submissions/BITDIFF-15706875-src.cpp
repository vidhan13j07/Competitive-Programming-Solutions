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
int x[33][2];
const ll mod=1e7+7;
int main() 
{
    int n,a,k=1;
    ll ans;
    TC() {
        scanf("%d",&n);
        f(j,0,32)
            x[j][0]=x[j][1]=0;
        ans=0;
        f(i,0,n) {
            scanf("%d",&a);
            for(int j=31;j>=0;j--)
                if(((1<<j)&a))
                    x[j][1]++;
                else
                    x[j][0]++;
        }
        f(i,0,32) {
            ans+=(x[i][0]*x[i][1]);
            if(ans>=mod)
                ans%=mod;
        }
        ans=(ans*2)%mod;
        printf("Case %d: %lld\n",k++,ans);
    }
    return 0;
}
