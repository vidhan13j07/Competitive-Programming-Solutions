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
int ar[N];
int main()
{
	TC() {
		int n;
		scanf("%d",&n);
		f(i,0,n) scanf("%d", ar+i);
		bool ok = 0, done = 0;
		int s = 0;
		f(i,0,n) {
			s += ar[i];
			if(ar[i] == 2) {
				done = 1;
				printf("No\n");
				break;
			}
			if(ar[i] == 5)
				ok = 1;
		}
		if(done)
			continue;
		double avg = (1.0*s)/(1.0*n);
		if(avg < 4 or !ok)
			printf("No\n");
		else
			printf("Yes\n");
	}
    return 0;
}
