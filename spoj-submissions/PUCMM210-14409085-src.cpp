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
#define m 1000000003
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
	ll A[1000010];
	int t;
	ll i,temp=0,n;
    for(i=1;i<=1000000;i++)
    {
       temp=(temp + i*i*i)%m;
       A[i]= (A[i-1] + temp)%m;
    }
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<A[n]<<endl;
	}
	return 0;
}