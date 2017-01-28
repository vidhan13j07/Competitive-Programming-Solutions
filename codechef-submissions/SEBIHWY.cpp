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
	TC() {
		int s, sg, fg, d, t, v, c;
		scanf("%d %d %d %d %d",&s, &sg, &fg, &d, &t);
		v = 180*d;
		if(v%t == 0) {
			v /= t;
			v += s;
			if(abs(v - sg) == abs(v - fg))
				c = 0;
			else if(abs(v - sg) > abs(v - fg))
				c = 1;
			else
				c = 2;
		}
		else {
			v += s*t;
			if(abs(v - sg*t) == abs(v - fg*t))
				c = 0;
			else if(abs(v - sg*t) > abs(v - fg*t))
				c = 1;
			else
				c = 2;
		}
		if(c == 0)
			printf("DRAW\n");
		else if(c == 1)
			printf("FATHER\n");
		else
			printf("SEBI\n");
	}
    return 0;
}
