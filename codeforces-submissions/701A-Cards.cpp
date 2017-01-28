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
int ar[N];
bool fl[N];
int main()
{
	int n, x = 0;
	cin>>n;
	f(i,0,n) {
		cin>>ar[i];
		x += ar[i];
		fl[i] = 0;
	}
	x *= 2;
	x /= n;
	f(i,0,n) {
		if(fl[i])
			continue;
		fl[i] = 1;
		int k = x - ar[i];
		f(j,i + 1,n) 
			if(!fl[j] and ar[j] == k) {
				fl[j] = 1;
				cout<<i + 1<<" "<<j + 1<<endl;
				break;
			}
	}
    return 0;
}