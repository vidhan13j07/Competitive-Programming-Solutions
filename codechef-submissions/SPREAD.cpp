#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
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
void FastIO()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
}
//TEMPLATE ENDS HERE
const int N=1e6+5;
vll val(4*N,0);
ll ans;
void update(int i,int a,int b,int l,int r,ll v)
{
    if(a>b or a>r or b<l)
        return ;
    if(a>=l and b<=r)
    {
        val[i]+=v;
        return ;
    }
    int mid=(a+b)/2;
    update(2*i,a,mid,l,r,v);
    update(2*i+1,mid+1,b,l,r,v);
}
void query(int i,int a,int b,int l)
{
    if(a>b or b<l or a>l)
        return ;
    if(l>=a and l<=b)
    {
        ans+=val[i];
        if(a==b)
            return ;
    }
    int mid=(a+b)/2;
    query(2*i,a,mid,l);
    query(2*i+1,mid+1,b,l);
}
int main() 
{
    FastIO();
    int n,q,l,r,p;
    ll v,c;
    char ch;
    cin>>n>>q>>c;
    while(q--)
    {
        cin>>ch;
        if(ch=='Q')
        {
            cin>>p;
            p--;
            ans=0;
            query(1,0,n-1,p);
            ans+=c;
            cout<<ans<<endl;
        }
        else if(ch=='S')
        {
            cin>>l>>r>>v;
            //cout<<v<<endl;
            l--;r--;
            update(1,0,n-1,l,r,v);
            //f(i,0,15)
              //  trace3(i,val[i],lazy[i]);
        }
    }
    return 0;
}
