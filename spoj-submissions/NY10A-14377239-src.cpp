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
	char s[45];
	char s1[8][4]={{'T','T','T'},{'T','T','H'},{'T','H','T'},{'T','H','H'},{'H','T','T'},{'H','T','H'},{'H','H','T'},{'H','H','H'}};
	int t,n,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		cout<<n<<" ";
		f(i,0,8)
		{
			c=0;
			f(j,0,38)
				if(s1[i][0]==s[j] and s1[i][1]==s[j+1] and s1[i][2]==s[j+2])
					c++;
			cout<<c<<" ";
		}
		cout<<endl;
	}
	return 0;
}