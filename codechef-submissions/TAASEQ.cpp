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
		int n, mi = INT_MAX;
		scanf("%d",&n);
		f(i,0,n) {
			scanf("%d", ar+i);
			mi = min(mi, ar[i]);
		}
		if(n <= 3) {
			printf("%d\n", mi);
			continue;
		}
		int diff = ar[1] - ar[0], id = -1;
		bool ok = 1;
		f(i,2,n)
			if(ar[i] - ar[i - 1] != diff) {
				if(id != -1) {
					ok = 0;
					break;
				}
				if(i + 1 == n) {
					id = i;
					break;
				}
				if(i + 1 < n) {
					if(ar[i + 1] - ar[i - 1] != diff)
						ok = 0;
					else {
						id = i;
						i++;
					}
				}
			}
		if(ok) {
			if(id == -1)
				printf("%d\n", mi);
			else
				printf("%d\n", ar[id]);
			continue;
		}
		diff = ar[n - 1] - ar[n - 2], id = -1;
		ok = 1;
		for(int i = n - 3;i >= 0;i--)
			if(ar[i + 1] - ar[i] != diff) {
				if(id != -1) {
					ok = 0;
					break;
				}
				if(i == 0) {
					id = i;
					break;
				}
				if(i >= 1) {
					if(ar[i + 1] - ar[i - 1] != diff)
						ok = 0;
					else {
						id = i;
						i--;
					}
				}
			}
		if(ok) {
			if(id == -1)
				printf("%d\n", mi);
			else
				printf("%d\n", ar[id]);
		}
		else
			printf("-1\n");
	}
    return 0;
}
