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
        int n;
        scanf("%d",&n);
        string ans = "";
        int ma = 0;
        f(i,0,n) {
            int c, cnt = 0;
            scanf("%d",&c);
            int ar[6] = {0, 0, 0, 0, 0, 0};
            cnt += c;
            while(c--) {
                int tmp;
                scanf("%d",&tmp);
                tmp--;
                ar[tmp]++;
            }
            sort(ar, ar + 6);
            cnt += 4*ar[0] + 2*(ar[1] - ar[0]) + (ar[2] - ar[1]);
            //trace2(i, cnt);
            if(cnt > ma) {
                if(i == 0)
                    ans = "chef";
                else {
                    ans = "";
                    int tmp = i + 1; 
                    while(tmp) {
                        ans += (char)('0' + tmp%10);
                        tmp /= 10;
                    }
                    reverse(all(ans));
                }
                ma = cnt;
            }
            else if(ma == cnt) {
                ans = "tie";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
