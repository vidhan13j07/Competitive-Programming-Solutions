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
int main() 
{
    int n,d;
    cin>>n>>d;
    f(i,0,n)
        cin>>p[i].fi>>p[i].se;
    sort(p,p+n);
    int i=0,j=1;
    ll frm=0,fr=0;
    while(i<n)
    {
        if(i==0)
            fr=p[i].se;
        else if(j>=i+1)
            fr-=p[i-1].se;
        else
        {
            fr=p[i].se;
            j=i+1;
        }
        //cout<<fr<<" ";
        while(j<n and p[j].fi-p[i].fi<d)
        {
            fr+=p[j].se;
            //cout<<"A ";
            j++;
        }
        //cout<<fr<<endl;
        frm=max(frm,fr);
        i++;
    }
    cout<<frm<<endl;
    return 0;
}