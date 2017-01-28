#include<bits/stdc++.h>
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define mk make_pair
#define fi first
#define se second
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
const int N = 55;
const ll mod = 1e9+7;
int ar[N], ans[N];
ll c = 0;
bool check(int start)
{
	int i = 1;
	while(start - 2*i >= 0)
	{
		if(ans[start] == ans[start - i] and ans[start] == ans[start - 2*i])
			return 0;
		i++;
	}
	return 1;
}
void cal(int start, int a, int k, int hamming, int end)
{
	if(start == end)
	{
		c++;
		if(c >= mod)
			c %= mod;
		return ;
	}
	f(i,0,a)
	{
		ans[start] = i;
		if(check(start))
		{
			if(ar[start] == i)
				cal(start + 1, a, k, hamming, end);
			else if(hamming + 1 <= k)
				cal(start + 1, a, k, hamming + 1, end);
		}
	}
}
int main()
{
	int a,k;
	string s;
	TC()
	{
		scanf("%d %d",&a,&k);
		cin>>s;
		if((a == 1 and sc(s) > 2) or (a == 2 and sc(s) > 8) or (a == 3 and sc(s) > 26))
		{
			printf("0\n");
			continue;
		}
		int i = 0;
		for(char ch:s)
			ar[i++] = ch - 'a';
		c = 0;
		cal(0, a, k, 0, sc(s));
		printf("%lld\n",c);
	}
    return 0;
}
