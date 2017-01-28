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
    int n;
    cin>>n;
    int r[n];
    int c[n-1];
    int lc[2][n+1],rc[2][n+1];
    f(i,0,2)
    {
        f(j,0,n-1)
            cin>>c[j];
        lc[i][0]=0;
        f(j,1,n)
            lc[i][j]=c[j-1]+lc[i][j-1];
        rc[i][n-1]=0;
        for(int j=n-2;j>=0;j--)
            rc[i][j]=c[j]+rc[i][j+1];
        /*f(j,0,n)
            cout<<lc[i][j]<<" ";
        cout<<endl;
        f(j,0,n)
            cout<<rc[i][j]<<" ";
        cout<<endl;*/
    }
    f(i,0,n)
        cin>>r[i];
    int ind=0,s=0;
    int mi=r[0]+lc[0][0]+rc[1][0];
    f(i,1,n)
    {
        int temp=r[i]+lc[0][i]+rc[1][i];
        if(mi>temp)
        {
            mi=temp;
            ind=i;
        }
    }
    //cout<<mi<<" "<<ind<<endl;
    s=mi;
    if(ind!=0)
    {
        mi=r[0]+rc[1][0]+lc[0][0];
        f(i,1,n)
        {
            if(i==ind)
                continue;
            int temp=r[i]+lc[0][i]+rc[1][i];
            mi=min(mi,temp);
        }
    }
    else
    {
        mi=r[1]+rc[1][1]+lc[0][1];
        f(i,2,n)
        {
            int temp=r[i]+lc[0][i]+rc[1][i];
            mi=min(mi,temp);
        }
    }
    s+=mi;
    cout<<s<<endl;
    return 0;
}