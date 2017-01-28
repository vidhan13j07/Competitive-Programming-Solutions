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
const int N=1e4+5;
int ar[N];
int main() 
{
	int n,temp;
	ll ans;
	TC()
	{
		scanf("%d",&n);
		ans=0;
		f(i,0,n)
		{
			scanf("%d",&temp);
			if(i==0)
			{
				ar[0]=1;
				continue;
			}
			if(!temp)
			{
				for(int j=i-1;j>=0;j--)
					ar[j+1]=ar[j];
				ar[0]=i+1;
			}
			else
			{
				int ind;
				for(int j=0;j<i;j++)
					if(ar[j]==temp)
					{
						ind=j;
						break;
					}
				//cout<<"ind "<<ind<<endl;
				for(int j=i-1;j>ind;j--)
					ar[j+1]=ar[j];
				ar[ind+1]=i+1;
				if(2*ind+2>i)
					ans+=i-ind-1;
				else
					ans+=ind+1;
			}
			//cout<<ans<<endl;
			//f(j,0,i)
			//	cout<<j<<" ";
			//cout<<endl;
		}
		//cout<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
