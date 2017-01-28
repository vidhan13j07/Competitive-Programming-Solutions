#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n, m;
	scanf("%lld %lld",&n, &m);
	ll mi = 0, ma = 0;
	ll k = n / m;
	ll l = n - m * k;
	mi += (m - l) * (((k) * (k - 1)) / 2);
	mi += l * ((k * (k + 1)) / 2);
	ma = ((n - m) * (n - m + 1))/2;
	cout<<mi<<" "<<ma<<endl;
    return 0;
}