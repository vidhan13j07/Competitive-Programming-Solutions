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
ll dp[2][30][(1<<9)];
int size;
ll cal(int i,int mask, int fl, string s) {
	if(sc(s) == i)
		return 1;
	ll &pos = dp[fl][i][mask];
	if(pos != -1) return pos;
	if(i == size) fl = 1;
	pos = 0;
	int temp;
	if(fl)	temp = s[i] - '0';
	else temp = 6;
	f(j,0,temp + 1) 
		if(!(mask&(1<<j)))
			pos += cal(i+1,mask | (1<<j),fl&j==temp,s);
	return pos;
}
int main()
{
	int n, m;
	string a, b;
	scanf("%d %d",&n, &m);
	n--;m--;
	memset(dp, -1 , sizeof(dp));
	a="";
	if(n == 0)
		a = "0";
	else {
		int temp = n;
		while(temp) {
			a += (temp%7 + '0');
			temp /= 7;
		}
		reverse(all(a));
	}
	if(m == 0)
		b = "0";
	else {
		int temp = m;
		while(temp) {
			b += (temp%7 + '0');
			temp /= 7;
		}
		reverse(all(b));
	}
	string s = a+b;
	size = sc(a);
	cout<<cal(0,0,1,s);
    return 0;
}