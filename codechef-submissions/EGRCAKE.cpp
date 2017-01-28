#include<bits/stdc++.h>
    #define ll long long int
    #define sc(v) v.size()
    #define eb emplace_back
    #define pb pop_back
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define TC() int t;cin>>t;while(t--)
    #define mk make_pair
    #define fi first
    #define se second 
    #define trace1(x)                cout <<#x<<": "<<x<<endl;
    #define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
    #define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
    #define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
    #define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
    #define vi vector<int>
    #define vll vector<ll>
    #define pi pair<int,int>
    #define pll pair<ll,ll>
    using namespace std;
    int main() 
    {
    	int n,m;
    	TC()
    	{
    		scanf("%d %d",&n,&m);
    		if(n==1)
    		{
    			printf("Yes\n");
    			continue;
    		}
    		if(m==0)
    		{
    			printf("No 1\n");
    			continue;
    		}
    		int cnt=__gcd(n,m);
    		if(cnt==1)
    			printf("Yes\n");
    		else
    			printf("No %d\n",n/cnt);
    	}
    	return 0;
    }
