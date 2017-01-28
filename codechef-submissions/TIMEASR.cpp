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
const double eps=1.0/120.0;
void print(int hr,int m)
{
	if(hr<10)
		printf("0%d:",hr);
	else
		printf("%d:",hr);
	if(m<10)
		printf("0%d\n",m);
	else
		printf("%d\n",m);
}
int main() 
{
	double angle,m,diff,h;
	TC()
	{
		scanf("%lf",&angle);
		f(i,0,12)
			f(j,0,60)
			{
				h=0.5*(i*60.0+j);
				m=j*6.0;
				diff=fabs(h-m);
				//if(i==11 or j==27)
				//	trace4(i,j,diff,angle);
				if(fabs(diff-angle)<=eps or fabs(360.0-diff-angle)<=eps)
					print(i,j);
			}
	}
	return 0;
}
