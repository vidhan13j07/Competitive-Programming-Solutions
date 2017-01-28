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
    int n,c,ma=0;
    cin>>n;
    string ar[n];
    f(i,0,n)
        cin>>ar[i];
    int visited[n]={0};
    f(i,0,n)
    {
        if(!visited[i])
        {
            c=1;
            f(j,i+1,n)
                if(!ar[i].compare(ar[j]))
                {
                    visited[j]=1;
                    c++;
                }
            ma=max(c,ma);
        }
    }
    cout<<ma<<endl;
    return 0;
}