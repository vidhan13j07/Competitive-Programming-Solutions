#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define max(a,b,c,d) max(a,max(b,max(c,d)))
using namespace std;
int main()
{
	int n,k;
	vector <int> v;
	v.eb(5);
	k=7;
	f(i,2,1001)
	{
		v.eb(k+v[i-2]);
		k+=3;
	}
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		n--;
		cout<<v[n]<<endl;
	}
	return 0;
}