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

const int N = 5005;
int ar[N];
int main()
{
	int n;
	scanf("%d",&n);
	int a[3];
	f(i,0,3) {
		printf("? %d %d\n", i%3 + 1, (i + 1)%3 + 1);
		fflush(stdout);
		scanf("%d", a+i);
	}
	ar[1] = (a[0] + a[1] - a[2])/2;
	ar[0] = (a[0] - a[1] + a[2])/2;
	ar[2] = (a[1] + a[2] - a[0])/2;
	f(i,3,n) {
		int tmp;
		printf("? 1 %d\n", i + 1);
		fflush(stdout);
		scanf("%d",&tmp);
		ar[i] = tmp - ar[0];
	}
	printf("! ");
	f(i,0,n)
		printf("%d ", ar[i]);
	fflush(stdout);
    return 0;
}