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
	int t,n,p,temp,count,ans=0,s=0;
	cin>>t;
	f(a,1,t+1)
	{
		cin>>n>>p;
		int ar[p]={0};
		int flag1=1,flag2=1,flag3=1;
		f(i,0,n)
		{
			count=0;
			f(j,0,p)
			{
				cin>>temp;
				if(temp)
				{
					count++;
					ar[j]++;
				}
			}
			if(count==0)
				flag2=0;
			if(count==p)
				flag3=0;
		}
		f(i,0,p)
			if(ar[i]==0)
				flag1=0;
		ans=0;
		if(flag1)
			ans+=4;
		if(flag2)
			ans+=2;
		if(flag3)
			ans+=1;
		cout<<"Case "<<a<<": "<<ans<<endl;
	}
	return 0;
}