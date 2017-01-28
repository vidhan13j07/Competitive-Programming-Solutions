#include<bits/stdc++.h>
#define ll long long int
#define sf(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define pf(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",a)
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;sf(t);while(t--)
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
int main() 
{
    ll n,temp,g;
    bool f=1;
    cin>>n;
    ll ar[n];
    cin>>ar[0]>>ar[1];
    g=__gcd(ar[0],ar[1]);
    f(i,2,n)
    {
        cin>>ar[i];
        g=__gcd(g,ar[i]);
    }
    f(i,0,n)
    {
        temp=ar[i]/g;
        while(temp!=1)
        {
            if(temp%3==0)
                temp/=3;
            else if(temp%2==0)
                temp/=2;
            else
                break;
        }
        if(temp!=1)
            f=0;
    }
    if(f)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}