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
pi p[N];
int pre[N],ar[N];
int main() 
{
    int n;
    cin>>n;
    f(i,0,n)
        cin>>p[i].fi>>p[i].se;
    sort(p,p+n);
    f(i,0,n)
        ar[i]=p[i].fi;
    pre[0]=pre[1]=0;
    f(i,1,n)
    {
        int x=max(p[i].fi-p[i].se,0);
        int ind=lower_bound(ar,ar+n,x)-ar;
        int k=i-ind;
        pre[i+1]=k+pre[ind];
    }
    int k=1,mi=pre[n];
    for(int i=n-1;i>=1;i--,k++)
        mi=min(mi,pre[i]+k);
    cout<<mi<<endl;
    return 0;
}