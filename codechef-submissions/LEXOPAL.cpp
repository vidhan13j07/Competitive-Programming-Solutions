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
        string s;
        cin>>s;
        int i = 0, j = sc(s) - 1;
        while(i <= j) {
            if(s[i] == '.' or s[j] == '.') {
                if(s[i] == '.' and s[j] == '.')
                    s[i] = s[j] = 'a';
                else if(s[i] == '.')
                    s[i] = s[j];
                else
                    s[j] = s[i];
            }
            if(s[i] != s[j]) {
                s = "-1";
                break;
            }
            i++;
            j--;
        }
        cout<<s<<endl;
    }
    return 0;
}
