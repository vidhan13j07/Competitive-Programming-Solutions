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
#define mem(a) memset(a,0,sizeof(a))
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
	int n,d,a;
	while(true)
	{
		cin>>n>>d;
		if(!n and !d)
			break;
		int ar[n+1];
		ar[1]=0;
		f(i,2,n+1)
		{
			ar[i]=(ar[i-1]+d)%i;
		//	cout<<ar[i]<<" ";
		}
		//cout<<endl;
		cout<<n<<" "<<d<<" "<<ar[n]+1<<endl;
	}
	return 0;
}