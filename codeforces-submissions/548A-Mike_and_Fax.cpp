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
    char st[1005];
    int k,t,i,n,j;
    cin>>st>>k;
    bool m=true;
    n=strlen(st);
    if(n%k!=0)
        m=false;
    t=n/k;
    //cout<<t<<endl;
    i=0;
    if(m)
    {
        while(i<n)
        {
            for(j=0;j<n and j<t/2;j++)
            {
                //cout<<st[i+j]<<" "<<st[i+t-j-1]<<endl;
                if(st[i+j]!=st[i+t-j-1])
                    m=false;
            }
            i=i+t;
            //cout<<i<<endl;
        }
    }
    if(m)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}