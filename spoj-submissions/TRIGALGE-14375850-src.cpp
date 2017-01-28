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
using namespace std;
int main()
{
	int t;
	double a,b,c,mid,i,j,s;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		i=0.0;
		j=100000.0;
		while(j-i>0.0000001)
		{
			mid=(i+j)/2;
			s=a*mid+b*sin(mid);
			if(abs(s-c)<=0.0000001)
				break;
			if(s>c)
				j=mid;
			else
				i=mid;
		}
		printf("%0.6f\n",mid);
	}
	return 0;
}