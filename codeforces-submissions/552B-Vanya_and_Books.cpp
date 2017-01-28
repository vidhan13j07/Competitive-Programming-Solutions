#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
int main() 
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,ans;
    cin>>n;
    /*dig=0;
    temp=n;
    while(temp)
    {
        dig++;
        temp/=10;
    }
    dig--;
    ans=0;
    while(dig)
    {
        power=pow(10,dig);
        ans+=(n-power+1)*(dig+1);
        dig--;
        n=power-1;
    }
    ans+=n;*/
    ans=0;
    long long int ar[10]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999};
    int i,j;
    for(i=0;i<9;i++)
        if(n<ar[i]) 
            break;
    for(j=1;j<i;j++)
        ans+=(j)*(ar[j]-ar[j-1]);
    ans+=j*(n-ar[i-1]);
    if(n==1000000000)
        ans++;
    cout<<ans<<endl;
    return 0;
}