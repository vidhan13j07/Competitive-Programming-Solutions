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
int main() 
{
    int n,temp;
    priority_queue< pair < int , pi > > pq;
    pair < int , pi > p;
    cin>>n;
    int k=2*n+1;
    f(i,2,k)
        f(j,1,i)
        {
            cin>>temp;
            pq.push(mk(temp,mk(i,j)));
        }   
    int vis[k];
    f(i,1,k)
        vis[i]=0;
    temp=k-1;
    int ar[k];
    while(temp>0)
    {
        p=pq.top();
        pq.pop();
        if(!vis[p.se.fi] and !vis[p.se.se])
        {
            vis[p.se.fi]=1;
            vis[p.se.se]=1;
            ar[p.se.fi]=p.se.se;
            ar[p.se.se]=p.se.fi;
            temp-=2;
        }
    }
    f(i,1,k)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}