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
/*auto max(auto a,auto b)
{
    if(a>b)
        return a;
    return b;
}*/
bool chk1(ll n)
{
    ll temp=(ll)(sqrt(n));
    //cout<<"chk "<<temp<<" "<<n/temp<<endl;
    if((ll)(temp*temp)==n)
        return 1;
    return 0;
}
bool chk(ll n)
{
    for(int i=1;i<=(int)(sqrt(n));i++)
        if(n%i==0)
        {
            //cout<<n<<" "<<i;
            if(i!=1 and chk1(i))
                return 0;
            //cout<<" "<<n/i<<endl;
            if((n/i)!=1 and chk1(n/i))
                return 0;
        }
    return 1;
}
int main() 
{
    ll n,ma=0;
    cin>>n;
    for(ll i=1;i<=(ll)(sqrt(n));i++)
        if(n%i==0)
        {
            if(chk(i))
                ma=max(ma,i);
            if(chk(n/i))
            {
                ma=n/i;
                break;
            }
        }
    cout<<ma<<endl;
    return 0;
}