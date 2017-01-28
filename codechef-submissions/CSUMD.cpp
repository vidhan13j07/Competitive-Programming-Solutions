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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
//TEMPLATE ENDS HERE
const int m=1e9+7;
ll ans1,ans2;
void power(ll n)
{
    ll sub[2][2]={{2,1},{2,0}},ret[2][2]={{1,0},{0,1}},tmp[2][2]={{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++)
                for(j=0; j<2; j++)
                    for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+(ret[i][k]*sub[k][j])%m)%m;
            for(i=0; i<2; i++)
                for(j=0; j<2; j++)
                    ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(i=0; i<2; i++) for(j=0; j<2; j++)
            for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+(sub[i][k]*sub[k][j])%m)%m;
        for(i=0; i<2; i++)
            for(j=0; j<2; j++)
                sub[i][j]=tmp[i][j];
        n/=2;
    }
    ans1=ret[0][0];
    ans2=ret[1][0];
}
int main() 
{
    FastIO();
    ll ans,n;
    //cout<<inv<<endl;
    TC()
    {
        cin>>n;
        if(n==1)
            cout<<"1"<<endl;
        else if(n==2)
            cout<<"3"<<endl;
        else
        {
            power(n-2);
            ans=(3*ans1+ans2)%m;
            cout<<ans<<endl;
        }
    }
	return 0;
}
