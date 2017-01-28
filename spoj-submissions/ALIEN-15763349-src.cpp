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
const int N=1e5+5;
int ar[N];
int main() 
{
	int n,k,ma_x,ma_h,ans;
	TC()
	{
		scanf("%d %d",&n,&k);
		f(i,0,n)
			scanf("%d",&ar[i]);
		int i=0,j=0;
		ma_h=0;
		ma_x=0;
		ans=0;
		while(j<n)
		{
			ma_h+=ar[j];
			while(ma_h>k)
			{
				ma_h-=ar[i];
				i++;
			}
			int x=j-i+1;
			if(x>ma_x)
			{
				ans=ma_h;
				ma_x=x;
			}
			else if(x==ma_x and ma_h<ans)
				ans=ma_h;
			j++;
		}
		printf("%d %d\n",ans,ma_x);
	}
	return 0;
}