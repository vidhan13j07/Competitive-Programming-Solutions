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
int main()
{
	double h, a, x, y;
	TC() {
		cin>>h>>a;
		if(h*h*h*h < 16*a*a) {
			printf("-1\n");
			continue;
		}
		x = h*h*h*h - 16.0*a*a;
		x = sqrt(x) + h*h;
		x /= 2.0;
		y = sqrt(h*h - x);
		x = sqrt(x);
		vector<double> v;
		v.eb(x);
		v.eb(y);
		v.eb(h);
		sort(all(v));
		f(i,0,sc(v))
			printf("%0.5lf ",v[i]);
			printf("\n");
		//printf("%0.5lf %0.5lf %0.5lf\n",x,y,h);
	}
    return 0;
}
