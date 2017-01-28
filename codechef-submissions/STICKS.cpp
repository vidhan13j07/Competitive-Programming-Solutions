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
const int N = 1e3 + 5;
int ar[N];
int main()
{
	TC() {
		f(i,0,N)
			ar[i] = 0;
		int n;
		scanf("%d",&n);
		f(i,0,n) {
			int temp;
			scanf("%d",&temp);
			ar[temp]++;
		}
		int a = -1,b = -1;
		bool ok = 0;
		for(int i = N- 1 ;i >= 0;i--) {
			if(ar[i] > 1) {
				if(!ok) {
					if(ar[i] > 3){
						a = i;
						b = i;
						break;
					}
					a = i;
					ok = 1;
				}
				else {
					b = i;
					break;
				}
			}
		}
		if(a == -1 or b == -1) {
			printf("-1\n");
			continue;
		}
		printf("%d\n",(a*b));
	}
    return 0;
}
