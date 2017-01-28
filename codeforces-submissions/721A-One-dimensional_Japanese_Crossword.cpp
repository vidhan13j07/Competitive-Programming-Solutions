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
int ans[N];
string s;
int main()
{
	int n, cnt;
	memset(ans, 0, sizeof ans);
	cin>>n>>s;
	bool flag = 1;
	if(s[0] == 'B'){
		flag = 1;
		cnt++;
	}
	else
		flag = 0;
	f(i,0,n) {
		if(s[i] == 'B' && flag){
			ans[cnt - 1]++;
		}
		else if(s[i] == 'B' && !flag){
			cnt++;
			ans[cnt - 1]++;
			flag = 1;
		}
		else{
			flag = 0;
		}
	}
	cout<<cnt<<endl;
	f(i,0,cnt)
		cout<<ans[i]<<" ";
    return 0;
}