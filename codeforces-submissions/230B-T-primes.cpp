#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
#define fi first
#define se second 
#define gcd __gcd
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define chk(a) if(a>=mod) a%mod;
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;

void FastIO()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
}
void die()
{
    cout<<"0"<<endl;
    exit(0);
}
//TEMPLATE ENDS HERE
const int N=1e6+5;
vector <int> primes(N,0);
vector <int> v;
/*void pre()
{
    v.eb(2);
    int i;
    for(i=3;i<N;i+=2)
    {
        if(chek[i])
        {
            v.eb(i);
            if(i<=1000)
            {
                for(int j=i*i,k=2*i;j<N;j+=k)
                    chek[j]=0;
            }
        }
    }
}*/
void pre()
{
    v.eb(2);
    for(int i = 3 ; i*i<=N ; i+=2)
    {
        if(!primes[i])
            for(int j = i*i ; j<N ; j+=2*i)
            {
                /*if(j==999983)
                    cout<<i<<endl;*/
                primes[j] = 1;
            }
    }
    for(int i = 3 ; i<N ; i+=2)
        if(!primes[i])
            v.eb(i);
}
int main() 
{
    FastIO();
    pre();
    int q;
    ll n,temp;
    cin>>q;
    while(q--)
    {
        cin>>n;
        temp=int(sqrt(n));
        //cout<<temp<<" "<<temp*temp<<" "<<primes[temp]<<endl;
        if(temp*temp==n and binary_search(v.begin(),v.end(),temp))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}