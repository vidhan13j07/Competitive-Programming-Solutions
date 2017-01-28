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
bool boys[105],girls[105];
int main() 
{
    int n,m,g,b,temp;
    cin>>n>>m;
    cin>>b;
    f(i,0,b)
    {
        cin>>temp;
        boys[temp]=1;
    }
    cin>>g;
    f(i,0,g)
    {
        cin>>temp;
        girls[temp]=1;
    }
    int lcm=(m*n)/__gcd(m,n);
    for(int i=0;i<=lcm*2;i++)
        if(boys[i%n] or girls[i%m])
        {
            boys[i%n]=1;
            girls[i%m]=1;
        }
    bool f=1;
    f(i,0,n)
        if(!boys[i])
            f=0;
    f(i,0,m)
        if(!girls[i])
            f=0;
    if(f)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    return 0;
}