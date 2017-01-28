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

string a;
int n, k;
int cal(char x) {
	int l = 0,r = 0, cnt = 0, ans = 0;
	while(r < n) {
		if(a[r] == x) cnt++;
		if(cnt <= k) {
			//cout<<"x\n";
			ans = max(ans, r - l + 1);
			r++;
		}
		else {
			if(a[l] == x) cnt--;
			//cout<<x<<" "<<y<<" "<<a[l]<<" y\n";
			l++;
			ans = max(ans, r - l + 1);
			r++;
		}
		//cout<<r<<" "<<cnt<<" "<<ans<<endl;
	}
	return ans;
}
int main()
{
	cin>>n>>k>>a;
	int ans = max(cal('a'), cal('b'));
	cout<<ans<<endl;
    return 0;
}
