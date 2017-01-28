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
const int N=505;
string st[N];
int row[N][N],col[N][N];
int main() 
{
    int h,w,q,r1,r2,c1,c2;
    scanf("%d %d",&h,&w);
    f(i,0,h)
        cin>>st[i];
    f(i,0,h)
    {
        row[i][0]=0;
        f(j,1,w)
        {
            row[i][j]=row[i][j-1];
            if(st[i][j]=='.' and st[i][j-1]=='.')
                row[i][j]++;
        }
    }
    f(j,0,w)
    {
        col[0][j]=0;
        f(i,1,h)
        {
            col[i][j]=col[i-1][j];
            if(st[i][j]=='.' and st[i-1][j]=='.')
                col[i][j]++;
        }
    }
    /*f(i,0,h)
    {
        f(j,0,w)
            cout<<row[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    f(i,0,h)
    {
        f(j,0,w)
            cout<<col[i][j]<<" ";
        cout<<endl;
    }*/
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        r1--;c1--;
        ll ans=0;
        f(i,r1,r2)
            ans+=row[i][c2-1]-row[i][c1];
        f(i,c1,c2)
            ans+=col[r2-1][i]-col[r1][i];
        printf("%lld\n",ans);
    }
    return 0;
}