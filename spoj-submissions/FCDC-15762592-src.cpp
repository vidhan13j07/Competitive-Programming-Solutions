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
const int N=1e7+5;
int fac[N];
void pre()
{
	vi v;
	f(i,0,N)
		fac[i]=0;
	f(i,2,N)
	{
		if(!fac[i])
		{
			fac[i]=i;
			v.eb(i);
		}
		int j=0;
		while(j<sc(v) and i*v[j]<N)
		{
			fac[i*v[j]]=v[j];
			j++;
		}
	}
}
int cal(int x,int c)
{
	int i=1,num,q;
	while(c>0)
	{
		num=i*x;
		q=num;
		while(num%x==0)
		{
			c--;
			num/=x;
		}
		i++;
	}
	return q;
}
int comp(int a)
{
	int ma=0,cnt,k;
	if(a==1)
		return a;
	while(a>1)
	{
		k=fac[a];
		cnt=0;
		while(a%k==0)
		{
			cnt++;
			a/=k;
		}
		//trace3(a,k,cnt);
		ma=max(ma,cal(k,cnt));
	}
	return ma;
}
int main() 
{
	pre();
	int a,b,max_a=0,max_b=0;
	scanf("%d %d",&a,&b);
	max_a=comp(a);
	max_b=comp(b);
	//cout<<max_a<<" "<<max_b<<endl;
	printf("%d\n",max(0,max_b-max_a));
	return 0;
}