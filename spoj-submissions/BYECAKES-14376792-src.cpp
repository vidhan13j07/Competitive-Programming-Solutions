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
#define max(a,b,c,d) max(a,max(b,max(c,d)))
using namespace std;
int main()
{
	int e1,f1,s1,m1,e2,f2,s2,m2,e3,f3,s3,m3,k;
	while(1)
	{
		cin>>e1>>f1>>s1>>m1>>e2>>f2>>s2>>m2;
		if(e1==-1)
			break;
		e3=ceil(1.0*e1/e2);
		f3=ceil(1.0*f1/f2);
		s3=ceil(1.0*s1/s2);
		m3=ceil(1.0*m1/m2);
		//cout<<e3<<" "<<f3<<" "<<s3<<" "<<m3<<endl;
		k=max(e3,f3,s3,m3);
		if(e1>=k*e2)
			e1=0;
		else
			e1=k*e2-e1;
		if(f1>=k*f2)
			f1=0;
		else
			f1=k*f2-f1;
		if(s1>=k*s2)
			s1=0;
		else
			s1=k*s2-s1;
		if(m1>=k*m2)
			m1=0;
		else
			m1=k*m2-m1;
		cout<<e1<<" "<<f1<<" "<<s1<<" "<<m1<<endl;
	}
	return 0;
}