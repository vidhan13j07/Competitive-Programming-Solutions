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
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,n,a,b,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll ar[n];
		f(i,0,n)
			cin>>ar[i];
		f(i,0,n)
		{
			if(ar[i]>=0)
			{
				if(ar[i]==1 or ar[i]==5)
					ar[i]=-3;
				else if(ar[i]==2)
					ar[i]=-2;
				else
					ar[i]=-4;
			}
			cout<<ar[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}