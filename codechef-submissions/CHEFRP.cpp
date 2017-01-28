#include <iostream>
    #define ll long long int
    #define s(x) scanf("%d",&x)
    #define p(x) printf("%d\n",x)
    using namespace std;
    int main() 
    {
    	int t,n,c,m;
    	ll sum,ans;
    	s(t);
    	while(t--)
    	{
    		c=0;sum=0,ans=0;
    		s(n);
    		int ar[n];
    		for(int i=0;i<n;i++)
    		{
    			s(ar[i]);
    			if(ar[i]<2)
    				c=1;
    			sum+=ar[i];
    			if(i==0)
    				m=ar[i];
    			else
    				m=min(m,ar[i]);
    		}
    		if(c==0)
    		{
    			ans=sum-m+2;
    			p(ans);
    		}
    		else
    			cout<<"-1"<<"\n";
    	}
    	return 0;
    }
