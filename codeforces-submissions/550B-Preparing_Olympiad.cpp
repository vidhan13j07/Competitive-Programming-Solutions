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
int n,l,r,x;
int ans=0;
vector<int> a,b;
 
bool isgood()
{
    int z = 0, S = 0, in = 1000000, ax = 1;
    for(int i=0; i<n; i++)
        if(b[i]==1)
        {
            z++;
            S += a[i];
            in = min(in,a[i]);
            ax = max(ax,a[i]);
        }
    if(S>=l && S<=r && (ax-in)>=x && z>=2)
        return true;
    return false;
}
void rcs(int i)
{
    if(i==n)
    {
        if(isgood())
            ans++;
        return; 
    }
    b[i] = 0;
    rcs(i+1);
    b[i] = 1;
    rcs(i+1);
}
int main()
{
    cin >> n >> l >> r >> x;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    rcs(0);
    cout<<ans;
    return 0;
}