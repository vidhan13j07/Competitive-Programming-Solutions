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
	std::ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,c,temp1,temp2,carry;
	while(1)
	{
		cin>>a>>b;
		if(a==0 and b==0)
			break;
		carry=0;
		c=0;
		while(a and b)
		{
			temp1=a%10;
			temp2=b%10;
			carry=(temp1+temp2+carry)/10;
			if(carry)
				c++;
			a/=10;
			b/=10;
			//cout<<a<<" "<<b<<" "<<carry<<" "<<c<<endl;
		}
		if(a>0)
			while(carry and a)
			{
				temp1=a%10;
				carry=(carry+temp1)/10;
				if(carry)
					c++;
				//cout<<a<<" "<<b<<" "<<carry<<" "<<c<<endl;
				a/=10;
				//cout<<a<<" "<<b<<" "<<carry<<" "<<c<<endl;
			}
		if(b>0)
			while(carry and b)
			{
				temp2=b%10;
				carry=(carry+temp2)/10;
				if(carry)
					c++;
				//cout<<a<<" "<<b<<" "<<carry<<" "<<c<<endl;
				b/=10;
				//cout<<a<<" "<<b<<" "<<carry<<" "<<c<<endl;
			}
		if(c>1)
			cout<<c<<" carry operations."<<endl;
		else if(c==1)
			cout<<"1 carry operation."<<endl;
		else
			cout<<"No carry operation."<<endl;
	}
	return 0;
}