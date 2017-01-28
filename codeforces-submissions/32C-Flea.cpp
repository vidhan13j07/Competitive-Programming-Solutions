#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pop pop_back
#define li(v,it) for(int it=0;it<sc(v);it++)
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main() 
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);
    ll x,y,z,t,ans,n,s,m;
    cin>>n>>m>>s;
    x = n%s;  
    y = m%s;  
    z = n/s;  
    t = m/s;  
    if(x==0)
        x=s;
    else
        z++;  
    if(y==0)
        y=s;
    else
        t++;  
    ans=x*y*z*t;  
    cout<<ans<<endl;
    return 0;
}