#include "bits/stdc++.h"
    using namespace std;
    #define f(i,n) for(int i = 1; i <=n ; ++i)
    #define ll long long
    #define MOD 1000000007
    int main()
    {
    	ll t;
        cin >> t;
        ll b[100001];
        b[0] = 1;
        f(i , 100000)
        b[i] = (b[i - 1]*2)%MOD;
        while(t--)
        {
           	ll n;
           	cin >>	n;
           	ll a[n + 1];
           	f(i , n)
           	cin >> a[i];
           	sort(a + 1, a + n + 1);
           	ll sum = 0;
           	f(i , n)
           	{
           		if((b[i - 1] - b[n - i])>=0)
           			sum += ((b[i - 1] - b[n - i]) * a[i])%MOD;
           		else
           			sum -= (abs(b[i - 1] - b[n - i]) * a[i])%MOD;
           		sum = sum%MOD;
           	}
           	cout<<sum<< "\n";
           	}
           	return 0;
        }
