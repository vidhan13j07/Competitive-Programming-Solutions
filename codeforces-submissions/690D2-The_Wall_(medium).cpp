#include<bits/stdc++.h>
using namespace std;
#define MOD 1000003
#define ll long long
ll factor[1000001];
ll fast_pow(ll a , ll b)
{
    ll x=1,y=a;
    while(b!=0)
    {
        if(b%2==1)
            x=(x*y)%MOD;
        y=(y*y)%MOD;
        b/=2;
    }
    return x;
}
void factorial()
{
    factor[0]=1;
    for (int i=1 ; i<=1000000 ; i++)
        factor[i]=(factor[i-1]*i)%MOD;
}
ll MMI(ll a)
{
    return fast_pow(a,MOD-2);
}
ll nCr(ll n , ll r)
{
    ll a=factor[n],b=(factor[r]*factor[n-r])%MOD;
    //cout<<a<<" "<<b<<endl;
    b=MMI(b);
    return (a*b)%MOD;
}
int main()
{
    int N,C;
    cin>>N>>C;
    ll Ans=0;
    factorial();
    for(int i=C ; i>=1 ; i--)
    {
        ll d=N+i-1;
        Ans=(Ans+nCr(d,i))%MOD;
    }
    cout<<Ans<<endl;
}
