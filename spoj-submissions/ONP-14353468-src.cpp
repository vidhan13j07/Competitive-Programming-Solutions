#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define mk make_pair
using namespace std;
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	int t,n;
	vector <char> v1;
	vector <char> v2;
	char st[405];
	cin>>t;
	while(t--)
	{
		cin>>st;
		v1.clear();
		v2.clear();
		n=strlen(st);
		for(int i=0;i<n;i++)
		{
			if(st[i]=='(')
				continue;
			else if(st[i]==')')
			{
				v1.eb(v2.back());
				v2.pb();
			}
			else if(st[i]=='+' or st[i]=='/' or st[i]=='^' or st[i]=='*' or st[i]=='-')
				v2.eb(st[i]);
			else
				v1.eb(st[i]);
		}
		//cout<<sc(v1)<<endl;
		for(int i=0;i<sc(v1);i++)
			cout<<v1[i];
		cout<<endl;
	}
	return 0;
}