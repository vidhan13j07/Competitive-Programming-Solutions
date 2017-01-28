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
set<ll> s;
const ll N=1e18+5;
ll ar[2000];
int main() 
{
    ll l,r,k=2;
    while(k<N)
    {
        s.insert(k);
        ll temp=k*3;
        while(temp<N)
        {
            s.insert(temp);
            temp*=3;
        }
        k*=2;
    }
    k=1;
    ar[0]=1;
    for(std::set<ll>::iterator it=s.begin();it!=s.end();it++)
        ar[k++]=*it;
    TC()
    {
        scanf("%lld %lld",&l,&r);
        int low=(std::lower_bound(ar,ar+k,l)-ar);
        int high=(std::lower_bound(ar,ar+k,r)-ar);
        int ans=high-low;
        if(ar[high]==r)
            ans++;
        printf("%d\n",ans);
        //cout<<low<<" "<<high<<endl;
    }
    //f(i,0,k)
    //    cout<<ar[i]<<" ";
    return 0;
}
