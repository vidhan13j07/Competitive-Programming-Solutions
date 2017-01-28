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
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int mat[n][n],x[n][n];
		f(i,0,n)
			f(j,0,n)
			{
				cin>>mat[i][j];
				if(j==0)
				    x[i][j]=mat[i][j];
				else
				    x[i][j]=x[i][j-1]^mat[i][j];
			}
		f(i,1,n)
		    f(j,0,n)
		        x[i][j]=x[i-1][j]^x[i][j];
		ll ma=0,temp;
	    f(i,0,n)
	       f(j,0,n)
	            f(k,i,n)
	                f(l,j,n)
	                {
	                    if(i>0 && j>0)
						    temp=x[k][l]^x[k][j-1]^x[i-1][l]^x[i-1][j-1];
						else if(i>0)
						    temp=x[k][l]^x[i-1][l];
						else if(j>0)
						    temp=x[k][l]^x[k][j-1];
						ma=max(ma,temp);
	                }
	   cout<<ma<<endl;
	}
	return 0;
}
