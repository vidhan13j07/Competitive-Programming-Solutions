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
const int N=2e5+5;
char st[N],ans[N];
int main() 
{
    cin>>st;
    int cnt[26];
    f(i,0,26)
        cnt[i]=0;
    for(auto ch : st)
        cnt[ch-'a']++;
    int a=0,l=strlen(st);
    f(i,0,26)
        if(cnt[i]&1)
            a++;
    f(i,0,26)
        if(cnt[i]&1)
        {
            if(a==1)
                continue;
            bool fl=0;
            for(int j=25;j>i;j--)
                if(cnt[j]&1)
                {
                    cnt[j]--;
                    fl=1;
                    break;
                }
            if(fl)
                cnt[i]++;
            a-=2;
        }
    int i=0,j=l-1;
    int k=0;
    char ch='a';
    while(k<26)
    {
        if(cnt[k]&1)
        {
            ans[l/2]=ch;
            cnt[k]--;
        }
        while(cnt[k] and i<=j)
        {
            ans[i++]=ch;
            ans[j--]=ch;
            cnt[k]-=2;
        }
        k++;
        ch++;
    }
    cout<<ans<<endl;
    return 0;
}