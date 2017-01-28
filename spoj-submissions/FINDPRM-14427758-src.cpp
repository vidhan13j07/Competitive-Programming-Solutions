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
bool primes[10000009];
int cum[10000009];
void pre(){
    for(int i = 3 ; i<= 3163 ; i+=2){
        if(!primes[i]){
            for(int j = i*i ; j<= 10000000 ; j+=2*i)
                primes[j] = 1;
        }
    }
    cum[2] = 1;
    for(int i = 3 ; i<10000000 ; i+=2)
    {
        if(primes[i] == 0 && i%2 != 0)
            cum[i] += cum[i-1] + 1;
        else
            cum[i] = cum[i-1];
        cum[i+1]=cum[i];
    }
}
int main(){
    int t;
    pre();
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n" , cum[n] - cum[(n>>1)]);
    }
    return 0;
}