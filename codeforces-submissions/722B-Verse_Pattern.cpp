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

const int N = 105;
int p[N];
int main()
{
	int n;
	cin>>n;
	f(i,0,n) cin>>p[i];
	bool fl = 1;
	string tmp;
	getline(cin, tmp);
	f(i,0,n) {
		string s;
		int c = 0;
		getline(cin, s);
		f(i,0,sc(s))
			if(s[i] == 'a' or s[i] =='e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] =='y')
				c++;
		//trace4(i, s, c, p[i]);
		if(c != p[i])
			fl = 0;
	}
	printf(fl?"YES":"NO");
    return 0;
}
