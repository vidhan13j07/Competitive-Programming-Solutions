#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
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
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
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
const int N=1000005;
bool ar[N];
vector <int> l(N);
vector <int> r(N);
vector <int> c(N);
int main() 
{
    FastIO();
    int n,m1,m2,mi,ma,temp;
    bool flag=0;
    f(i,0,N)
    {
        ar[i]=0;
        l[i]=-1;
        r[i]=-1;
        c[i]=0;
    }
    cin>>n;
    f(i,0,n)
    {
        cin>>temp;
        c[temp]++;
        if(ar[temp])
            r[temp]=i;
        else
        {
            l[temp]=i;
            ar[temp]=1;
        }
    }
    ma=0;
    mi=1e6;
    f(i,0,N)
    {
        if(c[i]>1)
            if(ma<c[i] or (ma==c[i] and r[i]-l[i]<mi))
            {
                ma=c[i];
                mi=r[i]-l[i];
                flag=1;
                m1=l[i]+1;
                m2=r[i]+1;
            }
    }
    if(flag)
        cout<<m1<<" "<<m2<<endl;
    else
        cout<<"1 1"<<endl;
    return 0;
}