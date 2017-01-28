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
    ll n,d,c=0;
    cin>>n>>d;
    ll ar[n];
    for(int i=0;i<n;i++)
        ar[i]=0;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);
    for(int i=0;i<n;i++)
        for(int j=i+1;(j<n) and (ar[j]-ar[i])<=d;j++)
        {
            c+=2;
            //cout<<ar[i]<<" "<<ar[j]<<endl;
        }
    cout<<c<<endl;
    return 0;
}