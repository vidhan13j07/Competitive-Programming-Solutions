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
const int N=1e5+5;
ll ar[N];
int main() 
{
    int n,sz;
    ll temp;
    TC()
    {
        scanf("%d",&n);
        sz=1;
        memset(ar,-1,sizeof(ar));
        f(i,0,n)
        {
            scanf("%lld",&temp);
            int ind=(std::upper_bound(ar,ar+sz,temp)-ar);
            //cout<<ind<<endl;
            if(1+ind>sz)
                sz++;
            ar[ind]=temp;
        }
        int sz1=0;
        f(i,0,sz+1)
            if(ar[i]!=-1)
                sz1++;
        cout<<sz1<<" ";
        f(i,0,sz+1)
            if(ar[i]!=-1)
                cout<<ar[i]<<" ";
        cout<<endl;
    }
    return 0;
}
