#include<bits/stdc++.h>
#define ll long long int
#define sf(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define pf(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",a)
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;sf(t);while(t--)
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
//vector< pair<int,pi> > v;
int main() 
{
    int n,k,a,b;
    TC()
    {
        //v.clear();
        scanf("%d %d",&n,&k);
        int st[n];
        f(i,0,n)
            st[i]=0;
        f(i,0,k)
        {
            scanf("%d %d",&a,&b);
			int count=0;
			for(int j=a;j<=b;j++)
            {
				if(count%2==0)
                {
					st[j]=1;
					count++;
				}
				else
                {
					st[j]=-1;
					count++;
				}
            }
        }
        k=0;
        f(i,0,n)
        {
            if(st[i]==1)
                k++;
            else if(st[i]==-1)
                k--;
            else if(k>0)
            {
                st[i]=-1;
                k--;
            }
            else if(k==0)
            {
                st[i]=1;
                k++;
            }
        }
        f(i,0,n)
            if(st[i]==1)
                printf("(");
            else
                printf(")");
        cout<<endl;
    }
    return 0;
}
