#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
#define fi first
#define se second 
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;
void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
//TEMPLATE ENDS HERE
int main() 
{
    FastIO();
    char a[15],b[15];
    TC()
    {
        cin>>a>>b;
        int n=strlen(a);
        bool f=1;
        f(i,0,n)
        {
            if(a[i]=='?' or b[i]=='?' or a[i]==b[i])
                continue;
            else
                f=0;
        }
        if(f)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}
