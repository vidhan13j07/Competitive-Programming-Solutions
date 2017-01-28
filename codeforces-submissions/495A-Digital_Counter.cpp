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
    int n,s,k;
    string st;
    cin>>st;
    n=sc(st);
    s=1;
    f(i,0,n)
    {
        k=st[i]-'0';
        if(k==0)
            s*=2;
        else if(k==1)
            s*=7;
        else if(k==2)
            s*=2;
        else if(k==3)
            s*=3;
        else if(k==4)
            s*=3;
        else if(k==5)
            s*=4;
        else if(k==6)
            s*=2;
        else if(k==7)
            s*=5;
        else if(k==8)
            s*=1;
        else if(k==9)
            s*=2;
    }
    cout<<s<<endl;
    return 0;
}