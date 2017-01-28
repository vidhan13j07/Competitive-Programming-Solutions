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
  ll n,m,d,ans=0;
  double x;
  cin>>n>>m;
  if(n==m)
    {
        cout<<"infinity"<<endl;
        return 0;
    }
    d=n-m;

    x=sqrt(d);
    for(int i=1;i<=x;i++)
    {
        if(d%i==0)
        {
            if(i>m)ans++;
            if(d/i > m && i!=d/i)ans++;
        }
    }
    cout<<ans<<endl;
  return 0;
}