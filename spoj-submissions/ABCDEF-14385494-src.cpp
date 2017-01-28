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
//a*b+c=d(e+f)
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	vector <int> v1;
	vector <int> v2;
	int n;
	cin>>n;
	int a[n];
	f(i,0,n)
		cin>>a[i];
	f(i,0,n)
		f(j,0,n)
			f(k,0,n)
			{
				v1.eb(a[i]*a[j]+a[k]);
				if(a[i])
					v2.eb(a[i]*(a[j]+a[k]));
			}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	long long count = 0;
	pair<vector<int>::iterator, vector<int>::iterator> bounds;
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		bounds = equal_range(v2.begin(), v2.end(), *it);
		count += bounds.second-bounds.first;
	}
	cout<<count<<endl;
	return 0;
}