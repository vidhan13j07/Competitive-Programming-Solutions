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
const int N=20005;
int ar[N];
int main() 
{
    int n,m,one,ans,temp;
    TC()
    {
        scanf("%d %d",&n,&m);
        one=0,ans=0;
        f(i,0,m)
        {
            scanf("%d",&ar[i]);
            if(ar[i]==1)
                one++;
        }
        if(m==1)
        {
            printf("0\n");
            continue;
        }
        temp=m-one;
        if(temp==0)
        {
            if(one<=3)
                ans++;
            else
                ans+=one/2;
        }
        else if(temp>one)
        {
            sort(ar,ar+m);
            int i=0,left=m;
	        while(i<m)
            {
	   	        if(ar[i]+2<=left)
                {
	                left-=(ar[i]+1);
	                ans+=ar[i];
	            }
	            else
                {
	   	            ans+=left-1;
	   	            break;
	            }
                i++;
            }
        }
        else
            ans+=(one+temp)/2;
        printf("%d\n",ans);
    }
    return 0;
}
