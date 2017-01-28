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
	string s;
	cin>>s;
	bool fl = 0;
	f(i,0,sc(s)) {
		if(i + 26 > sc(s))
			break;
		int ar[26];
		f(j,0,26)
			ar[j] = 0;
		int k = i, c = 0;
		while(k < i + 26) {
			if(s[k] == '?')
				c++;
			ar[s[k] - 'A']++;
			k++;
		}
		int x = 0;
		vector<char> ch;
		f(j,0,26)
			if(!ar[j]) {
				x++;
				ch.eb((char)('A' + j));
			}
		if(x > c)
			continue;
		for(auto j: ch)
			f(k,i,i + 26)
				if(s[k] == '?') {
					s[k] = j;
					break;
				}
		fl = 1;
	}
	f(i,0,sc(s))
		if(s[i] == '?')
			s[i] = 'A';
	if(fl)
		cout<<s;
	else
		cout<<"-1";
    return 0;
}