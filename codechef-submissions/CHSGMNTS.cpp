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
map<int, int> mp;
int ar[N], before[N];
bool fl[N];
int main()
{
	TC() {
		mp.clear();
		int n;
		scanf("%d",&n);
		f(i,0,n) {
			scanf("%d",ar+i);
			if(mp.find(ar[i]) == mp.end()) 
				before[i] = -1;
			else
				before[i] = mp[ar[i]];
			mp[ar[i]] = i;
		}
		if(n == 0) {
			printf("0\n");
			continue;
		}
		ll ans = 0, prev;
		int ind;
		f(i,1,n) {
			memset(fl, 0, sizeof fl);
			for(int j = i;j >= 1;j--) {
				int k = before[j];
				bool ok = 1;
				while(k != -1 and !fl[k]) {
					fl[k] = 1;
					k = before[k];
					ok = 0;
				}
				if(j != i and ok) {
					if(j <= ind) {
						ind--;
						ll cnt = 0;
						while(ind >= 0 and !fl[ind]) {
							ind--;
							cnt++;
						}
						if(ind == -1)
							ind = 0;
						prev -= (cnt*(cnt + 1))/2;
					}
					ll cnt = j - ind - 1;
					if(cnt < 0)
						continue;
					if(ind == 0 and !fl[ind])
						cnt++;
					ans += (cnt*(cnt+1))/2;
					ans += prev;
					//trace5(i,j,ind,prev,ans);
					continue;
				}
				k = 0;
				prev = 0;
				ind = 0;
				while(k < j) {
					ll l = 0;
					while(!fl[k] and k < j) {
						l++;
						k++;
				    }
				    if(k != j)
				    	prev += (l*(l + 1))/2;
				    else
				    	ans += (l*(l + 1))/2;
					while(fl[k] and k < j) {
						ind = k;
						k++;
					}
				}
				ans += prev;
				//trace3(i,j,ans);
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}
