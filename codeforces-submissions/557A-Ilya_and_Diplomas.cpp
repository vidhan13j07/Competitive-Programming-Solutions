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
    int n,a,b,c,d,e,f,s1,s2,s3;
    cin>>n;
    cin>>a>>b>>c>>d>>e>>f;
    n=n-e-c-a;
    s1=a;
    s2=c;
    s3=e;
    if(n>0)
    {
        if(b-a<=n)
        {
            s1=b;
            n-=(b-a);
        }
        else
        {
            s1=n+a;
            n=-1;
        }
        if(n>0)
        {
            if(d-c<=n)
            {
                s2=d;
                n-=(d-c);
            }
            else
            {
                s2=n+c;
                n=-1;
            }
            if(n>0)
                s3=n+e;
        }
    }
    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    return 0;
}