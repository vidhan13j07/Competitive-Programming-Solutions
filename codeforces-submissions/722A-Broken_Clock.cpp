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
	if(s[3] > '5')
		s[3] = '5';
	if(n == 24) {
		if(s[0] > '2')
			s[0] = '0';
		else if(s[0] == '2' and s[1] >= '4')
			s[1] = '1';
	}
	else {
		if(s[0] > '1') {
			if(s[1] > '0')
				s[0] = '0';
			else
				s[0] = '1';
		} 
		else if(s[0] == '1') {
			if(s[1] >= '3')
				s[1] = '0';
		} 
		else if(s[1] == '0' && s[0] == '0') 
			s[1] = '1';
	}
	cout<<s;
    return 0;
}
