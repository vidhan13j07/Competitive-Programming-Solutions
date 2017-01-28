#include<iostream>
    #define ll long long int
    using namespace std;
    ll gcd(ll a,ll b)
    {
    	if(b==0)
    		return a;
    	else
    		return gcd(b,a%b);
    }
    int main()
    {
    	ll a,b,g;
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		cin>>a>>b;
    		g=gcd(a,b);
    		b/=g;
    		while (true)
    		{
    			g=gcd(b,g);
    			b=b/g;
    			if(g==1)
    				break;
    		}
    		if(b==1)
    			cout<<"Yes"<<"\n";
    		else
    			cout<<"No"<<"\n";
    	}
    	return 0;
    }
