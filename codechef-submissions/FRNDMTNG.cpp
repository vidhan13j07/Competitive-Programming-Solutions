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
	std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	double t1,t2,T1,T2,a,b,c,d,e,f,ans,s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>T1>>T2>>t1>>t2;
		if(t1>T2)
			t1=T2;
		if(t2>T1)
			t2=T1;
		a=(t1/T1);
		b=(t1/T2);
		c=(t2/T1);
		d=(t2/T2);
		e=(T1/T2);
		f=(T2/T1);
		s=(t1+t2);
		if(T2-T1>t1)
			ans=(s/T2)-((c*d)/2.0);
		else if(T1-T2>t2)
			ans=(s/T1)-((a*b)/2.0);
		else
			ans=a+d-((a*b)/2.0)-((c*d)/2.0)-((1-f)*(e-1))/2.0;
		cout<<std::fixed<<setprecision(6)<<ans<<endl;
	}
	return 0;
}
