#include <iostream>
#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
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
    int n,m,q,i,j,k,ma=0,a,b,st=-1;
    cin>>n>>m>>q;
    int ar[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>ar[i][j];
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<ar[i][j]<<" ";
        cout<<endl;
    }*/
    int store[n];
    for(i=0;i<n;i++)
    {
        k=0;
        store[i]=0;
        //cout<<i<<endl;
        for(j=0;j<m;j++)
        {
            //cout<<"entered"<<endl;
            if(ar[i][j])
                k++;
            else
            {
                store[i]=max(store[i],k);
                k=0;
            }
            //cout<<j<<" "<<ar[i][j]<<" "<<k<<" "<<m<<endl;
        }
        store[i]=max(k,store[i]);
    }
    //for(i=0;i<n;i++)
    //  cout<<store[i]<<endl;
    while(q--)
    {
        cin>>a>>b;
        a--;
        b--;
        if(ar[a][b])
            ar[a][b]=0;
        else
            ar[a][b]=1;
        //cout<<a<<" "<<b<<" "<<ar[a][b]<<endl;
        store[a]=0;
        k=0;
        for(j=0;j<m;j++)
            if(ar[a][j])
                k++;
            else
            {
                store[a]=max(store[a],k);
                k=0;
            }
        store[a]=max(k,store[a]);
        if(ma<m or a==st)
        {
            ma=0;
            for(i=0;i<n;i++)
                if(store[i]>ma)
                {
                    ma=store[i];
                    st=i;
                }
        }
        //for(i=0;i<n;i++)
        //  cout<<store[i]<<" ";
        //cout<<endl;
        cout<<ma<<endl;
    }
    return 0;
}