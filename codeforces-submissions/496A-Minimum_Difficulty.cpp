#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
#define fi first
#define se second 
#define gcd __gcd
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define chk(a) if(a>=mod) a%mod;
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;

void FastIO()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
}
void die()
{
    cout<<"0"<<endl;
    exit(0);
}
ll power(ll a,ll b)
{
    ll x=1;
    while(b)
    {
        if(b&1)
            x*=a;
        a*=a;
        chk(x);
        chk(a);
        b>>=1;
    }
    return x;
}
//TEMPLATE ENDS HERE
vi v;
int main() 
{
    FastIO();
    int n,d,ma;
    cin>>n;
    int ar[n];
    f(i,0,n)
        cin>>ar[i];
    d=1e9;
    f(i,1,n-1)
    {
        ma=0;
        v.clear();
        f(j,0,n)
            if(i==j)
                continue;
            else
                v.eb(ar[j]);
        f(j,1,sc(v))
            ma=max(ma,v[j]-v[j-1]);
        d=min(d,ma);
    }
    cout<<d<<endl;
    return 0;
}