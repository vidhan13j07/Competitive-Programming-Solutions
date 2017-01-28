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
#define endl "\n"
#define eps 1e-9
#define pw(x) (1ll<<(x))
#define trace1(x)                cout <<#x<<": "<<x<<endl;
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

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    //clock_t tStart = clock();
    int n;
    string st;
    cin>>n;
    cin>>st;
    int r=0,b=0,g=0;
    for(auto i:st)
    	if(i=='R')
    		r++;
    	else if(i == 'B')
    		b++;
    	else
    		g++;
    if((r && g && b) || (r == 0 && b > 1 && g > 1) || (b == 0 && g > 1 && r > 1) || (g == 0 && r > 1 && b > 1)) 
    	cout<<"BGR\n";
    else if((r == 0 && g == 0) || (b == 0 && r == 1 && g == 1))
        cout<<"B\n";
    else if((r == 0 && b == 0) || (g == 0 && r == 1 && b == 1))
        cout<<"G\n";
    else if((g == 0 && b == 0) || (r == 0 && g == 1 && b == 1))
        cout<<"R\n";
    else if(b*g == 0 && r > 1)
    	cout<<"BG\n";
    else if(r*b == 0 && g > 1)
        cout<<"BR\n";
    else if(r*g == 0 && b > 1)
    	cout<<"GR\n";
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}