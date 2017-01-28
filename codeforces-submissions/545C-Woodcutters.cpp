#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
//const int l=100005;
using namespace std;
int main()
{
    int n,ans,i;
    cin>>n;
    ll ar[n+1][2],a,b,c,d,e;
    for(i=0;i<=n;i++)
    {
        ar[i][0]=0;
        ar[i][1]=0;
    }
    ans=1;
    for(i=0;i<n;i++)
        cin>>ar[i][0]>>ar[i][1];
    c=ar[0][0]-ar[0][1];
    d=ar[0][0]+ar[0][1];
    b=ar[0][0];
    a=max(b,min(c,d));
    for(i=1;i<n-1;i++)
    {
        if(max(c,e)<max(d,e))
        {
        c=ar[i][0]-ar[i][1];
        d=ar[i][0]+ar[i][1];
        e=ar[i][0];
        if(min(c,e)>a and (max(c,e)<ar[i+1][0]))
        {
            ans++;
            a=max(c,e);
        }
        else if(min(d,e)>a and (max(d,e)<ar[i+1][0]))
        {
            ans++;
            a=max(d,e);
        }
        else
            a=ar[i][0];
        }
        else{
        c=ar[i][0]-ar[i][1];
        d=ar[i][0]+ar[i][1];
        e=ar[i][0];
        if(min(c,e)>a and (max(c,e)<ar[i+1][0]))
        {
            ans++;
            a=max(c,e);
        }
        else if(min(d,e)>a and (max(d,e)<ar[i+1][0]))
        {
            ans++;
            a=max(d,e);
        }
        else
            a=ar[i][0];
        }
    }
    c=ar[i][0]-ar[i][1];
    d=ar[i][0]+ar[i][1];
    e=ar[i][0];
    if(min(c,e)>a)
        ans++;
    else if(min(d,e)>a)
        ans++;
    cout<<ans<<endl;
    return 0;
}