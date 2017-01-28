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
int main() 
{
    unsigned long long int a,b,cnt=0,ar[65],k,s;
    cin>>a>>b;
    //trace2(a,b);
    ar[0]=1;
    f(i,1,60)
        ar[i] = 2*ar[i-1];
    //cout<<s<<endl;
    for(int i=59;i>0;i--)
    {
        s=0;
        f(j,0,i+1)
            s+=ar[j];
        for(int j=0;j<i;j++)
        {
            k=s-ar[j];
            //cout<<k<<endl;
            if(k>=a and k<=b)
                cnt++;
        }
        //cout<<s<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}