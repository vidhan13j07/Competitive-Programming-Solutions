#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
using namespace std;
int main()
{
    ll k,n,w,mon,ans;
    cin>>k>>n>>w;
    mon=((w+1)*w*k)/2;
    ans=mon-n;
    //cout<<ans<<endl;
    if(ans<0)
        ans=0;
    cout<<ans<<endl;
    return 0;
}