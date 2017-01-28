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
	int n, n1, n2;
	scanf("%d %d %d",&n, &n1, &n2);
	f(i,0,n)
		scanf("%d", ar+i);
	sort(ar, ar+n);
	double a = 0.0, b = 0.0;
	reverse(ar, ar + n);
	f(i,0,min(n1, n2))
		a += 1.0*ar[i];
	f(i,min(n1, n2), n1 + n2)
		b += 1.0*ar[i];
	a /= (1.0*min(n1,n2));
	b /= (1.0*max(n1, n2));
	a += b;
	printf("%0.10lf\n", a);
    return 0;
}