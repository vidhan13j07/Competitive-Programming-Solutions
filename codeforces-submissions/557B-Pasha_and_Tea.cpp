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
#define endl "\n"
#define fi first
#define se second 
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
    ll n,w,a,b,temp;
    cin>>n>>w;
    double s,c,x;
    vector <ll> v;
    f(i,0,2*n)
    {
        cin>>temp;
        v.eb(temp);
    }
    sort(v.begin(),v.end());
    a=v[0];
    b=v[n];
    if(b>=2*a)
        s=a*n+2*a*n;
    else
    {
        c=b/2.0;
        s=c*n+b*n;
    }
    if(s>(double)w)
        s=w;
    cout<<std::fixed<<setprecision(6)<<s<<endl;
    return 0;
}