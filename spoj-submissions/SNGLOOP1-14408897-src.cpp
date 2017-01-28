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
int main(){
    long long t,m,n,p;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&m);
        p=(m-n)%4;
        if(p==1)
            printf("3\n");
        else if(p==2)
            printf("9\n");
        else if(p==3)
            printf("7\n");
        else
            printf("1\n");
    }
    return 0;
}