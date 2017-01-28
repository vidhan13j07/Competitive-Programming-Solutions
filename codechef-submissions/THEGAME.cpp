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
    char str[6000][6000];
    int coun;
    int dfs(int r,int c,int i,int j)
    {
        if(i<0 or j<0 or i>=r or j>=c or str[i][j]=='#')
            return 0;
        str[i][j]='#';
        return (1+dfs(r,c,i+1,j)+dfs(r,c,i-1,j)+dfs(r,c,i,j+1)+dfs(r,c,i,j-1));
    }
    int main() 
    {
        int reach,t,r,c;
        double ans;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d %d",&r,&c);
            ans=1.0;
            f(i,0,r)
                cin>>str[i];
            reach=dfs(r,c,r-1,c-1);
            f(i,0,r)
            {
                f(j,0,c)
                {
                    coun=0;
                    if(str[i][j]=='o')
                        coun=dfs(r,c,i,j);
                    ans+=(1.0*coun)/(coun+reach);
                }
            }
            printf("%0.10lf\n",ans);
        }
        return 0;
    }
