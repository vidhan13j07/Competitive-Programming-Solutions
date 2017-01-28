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

const int N = 1e5 + 5;
int d[N], ar[N];
set<int> st;
int main()
{
	int n, m;
	scanf("%d %d",&n, &m);
	f(i,0,n) scanf("%d", d+i);
	f(i,0,m) scanf("%d", ar+i);
	int s = m;
	f(i,0,m) {
		s += ar[i];
		ar[i]++;
	}
	if(s > n) {
		printf("-1\n");
		return 0;
	}
	int cnt = 0;
	f(i,0,n) {
		d[i] -= 1;
		if(d[i] == -1)
			continue;
		if(st.find(d[i]) == st.end()) {
			st.insert(d[i]);
			cnt += ar[d[i]];
		}
		if(i + 1 >= cnt and sc(st) == m) {
			printf("%d\n", (i + 1));
			return 0;
		}
	}
	printf("-1\n");
    return 0;
}