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
void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
//TEMPLATE ENDS HERE
const int INF=1e8;
int main() 
{
    FastIO();
    int n,c1,c2;
    string a,b;
    bool ans1,ans2;
    char s1,s2;
    TC()
    {
        ans1=1;ans2=1;
        c1=0;c2=0;
        s1='1';s2='2';
        cin>>a>>b;
        if(a[0]=='#' and b[0]=='#')
        {
            cout<<"No"<<endl;
            continue;
        }
        else if(a[0]=='#')
            ans1=0;
        else if(b[0]=='#')
            ans2=0;
        n=sc(a);
        f(i,1,n)
        {
            if(s1=='1')
            {
                if(a[i]=='#' and b[i]=='#')
                {
                    if(i+1<n)
                    {
                        if(b[i+1]=='#')
                            ans1=0;
                        else
                        {
                            c1++;
                            s1='2';
                        }
                    }
                    else
                        ans1=0;
                }
                else if(a[i]=='#' and b[i]=='.')
                {
                    c1++;
                    s1='2';
                }
            }
            else if(s1=='2')
            {
                if(a[i]=='#' and b[i]=='#')
                {
                    if(i+1<n)
                    {
                        if(a[i+1]=='#')
                            ans1=0;
                        else
                        {
                            c1++;
                            s1='1';
                        }
                    }
                    else
                        ans1=0;
                }
                else if(b[i]=='#' and a[i]=='.')
                {
                    c1++;
                    s1='1';
                }
            }
            if(s2=='1')
            {
                if(a[i]=='#' and b[i]=='#')
                {
                    if(i+1<n)
                    {
                        if(b[i+1]=='#')
                            ans2=0;
                        else
                        {
                            c2++;
                            s2='2';
                        }
                    }
                    else
                        ans2=0;
                }
                else if(a[i]=='#' and b[i]=='.')
                {
                    c2++;
                    s2='2';
                }
            }
            else if(s2=='2')
            {
                if(a[i]=='#' and b[i]=='#')
                {
                    if(i+1<n)
                    {
                        if(a[i+1]=='#')
                            ans2=0;
                        else
                        {
                            c2++;
                            s2='1';
                        }
                    }
                    else
                        ans2=0;
                }
                else if(b[i]=='#' and a[i]=='.')
                {
                    c2++;
                    s2='1';
                }
            }
        }
        if(ans1 and ans2)
            cout<<"Yes\n"<<min(c1,c2)<<endl;
        else if(ans1)
            cout<<"Yes\n"<<c1<<endl;
        else if(ans2)
            cout<<"Yes\n"<<c2<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}
