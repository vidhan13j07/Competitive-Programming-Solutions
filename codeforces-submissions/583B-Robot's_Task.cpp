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
const int N=1005;
int ar[N];
bool vis[N];
int main() 
{
    int n,temp;
    cin>>n;
    f(i,0,n)
    {
        cin>>ar[i];
        vis[i]=0;
    }
    int c=-1,done=0;
    while(done<n)
    {
        f(i,0,n)
            if(!vis[i] and ar[i]<=done)
            {
                done++;
                vis[i]=1;
            }
        c++;
        if(done==n)
            break;
        for(int i=n-1;i>=0;i--)
            if(!vis[i] and ar[i]<=done)
            {
                done++;
                vis[i]=1;
            }
        c++;
    }
    if(c==-1)
        c=0;
    cout<<c<<endl;
    return 0;
}