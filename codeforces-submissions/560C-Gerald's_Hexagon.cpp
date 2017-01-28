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
double area(double a,double b,double c)
{
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main() 
{
    FastIO();
    double a,b,c,d,e,f,x1,x2,x3,a1,a2,a3,a4,s;
    cin>>a>>b>>c>>d>>e>>f;
    x1=sqrt(a*a+b*b+a*b);
    x2=sqrt(c*c+d*d+c*d);
    x3=sqrt(e*e+f*f+e*f);
    //cout<<x1<<" "<<x2<<" "<<x3<<endl;
    a1=area(a,b,x1);
    a2=area(c,d,x2);
    a3=area(e,f,x3);
    a4=area(x1,x2,x3);
    //cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
    s=(4*(a1+a2+a3+a4))/sqrt(3);
    cout<<(int)s<<endl;
    return 0;
}