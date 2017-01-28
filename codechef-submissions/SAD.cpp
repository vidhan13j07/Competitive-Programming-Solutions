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
int mat[100][100];
int main() 
{
    FastIO();
    int r,c;
    ll ma,mi,ans=-1;
    cin>>r>>c;
    f(i,0,r)
        f(j,0,c)
            cin>>mat[i][j];
    f(i,0,r)
    {
        mi=1000000000;
        f(j,0,c)
            mi=min(mi,mat[i][j]);
        //trace2(i,mi);
        f(j,0,c)
        {
            if(mat[i][j]==mi)
            {
                ma=0;
                f(k,0,r)
                    ma=max(ma,mat[k][j]);
                if(ma==mi)
                    ans=ma;
            }
        }
    }
    if(ans==-1)
        cout<<"GUESS"<<endl;
    else
        cout<<ans<<endl;
	return 0;
}
