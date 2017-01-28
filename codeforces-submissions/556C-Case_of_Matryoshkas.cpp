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
    int n,k,c,ans=0,temp;
    cin>>n>>k;
    int ar[n];
    while(k--)
    {
        cin>>temp;
        f(j,0,temp)
            cin>>ar[j];
        if(ar[0]==1)
        {
            c=1;
            f(j,1,temp)
                if(ar[j]-ar[j-1]==1)
                    c++;
                else
                    break;
            ans+=2*(temp-c);    
        }
        else
            ans+=2*temp-1;
    }
    cout<<ans<<endl;
    return 0;
}