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
map< string,vector<string> > mp;
int main() 
{
    int n;
    string st,temp,special="bmail.com",domain;
    cin>>n;
    while(n--)
    {
        cin>>st;
        int l=sc(st),i;
        domain="",temp="";
        for(i=l-1;i>=0 and st[i]!='@';i--)
            domain+=tolower(st[i]);
        std::reverse(std::begin(domain),std::end(domain));
        if(domain==special)
        {
            int j;
            for(j=0;j<i;j++)
            {
                if(st[j]=='+')
                    break;
                if(st[j]!='.')
                    temp+=tolower(st[j]);
            }
        }
        else
        {
            int j;
            for(j=0;j<i;j++)
                temp+=tolower(st[j]);
        }
        temp+=("@"+domain);
        mp[temp].eb(st);
    }
    cout<<sc(mp)<<endl;
    for(std::map< string,vector<string> >::iterator it=mp.begin();it!=mp.end();it++)
    {
        cout<<sc(it->se)<<" ";
        for(auto a:it->se)
            cout<<a<<" ";
        cout<<endl;
    }
    return 0;
}