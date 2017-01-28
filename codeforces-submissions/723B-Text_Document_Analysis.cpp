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

int main()
{
	int n;
	string s;
	cin>>n>>s;
	int c = 0, a = 0, b = 0, i = 0;
	bool fl = 0;
	while(i < n) {
		int j = i;
		string ss = "";
		while(j < n and s[j] != '(' and s[j] != '_' and s[j] != ')')
			ss += s[j++];
		if(!fl)
			a = max(a, (int)sc(ss));
		else if(sc(ss) > 0)
			b++;
		if(s[j] == '(')
			fl = 1;
		else if(s[j] == ')')
			fl = 0;
		i = j + 1;
	}
	cout<<a<<" "<<b;
    return 0;
}