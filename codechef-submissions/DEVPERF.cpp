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
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
using namespace std;
const int N=1005;
string st[N];
int main() 
{
	int n,m,ans,start_row,start_col,end_row,end_col;
	TC()
	{
		scanf("%d %d",&n,&m);
		f(i,0,n)
			cin>>st[i];
		bool fl=1,row=1,col=1;
		f(i,0,n)
			f(j,0,m)
				if(st[i][j]=='*')
				{
					if(row)
					{
						start_row=i;
						row=0;
					}
					end_row=i;
					fl=0;
				}
		f(j,0,m)
			f(i,0,n)
				if(st[i][j]=='*')
				{
					if(col)
					{
						start_col=j;
						col=0;
					}
					end_col=j;
				}
		if(fl)
			ans=0;
		else
		{
			ans=N*N;
			f(i,0,n)
				f(j,0,m)
					ans=min(ans,max4(abs(start_row-i),abs(end_row-i),abs(start_col-j),abs(end_col-j)));
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
