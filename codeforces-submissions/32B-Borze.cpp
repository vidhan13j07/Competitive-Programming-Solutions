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
    char st[205];
    for(int i=0;i<205;i++)
        st[i]='\0';
    vector <char> v;
    cin>>st;
    int i,n;
    n=strlen(st);
    i=0;
    while(i<n-1)
    {
        if(st[i]=='-')
        {
            if(st[i+1]=='-')
                v.eb('2');
            else
                v.eb('1');
            i++;
        }
        else
            v.eb('0');
        i++;
    }
    if(i!=n)
        v.eb('0');
    for(i=0;i<sc(v);i++)
        cout<<v[i];
    cout<<endl;
    return 0;
}