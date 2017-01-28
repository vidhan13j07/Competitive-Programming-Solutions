#include<bits/stdc++.h>
                #define sc(v) v.size()
                #define eb push_back
                #define pb pop_back
                #define f(i,a,b) for(int i=a;i<b;i++)
                #define TC() int t;cin>>t;while(t--)
                #define all(x) x.begin(),x.end()
                #define mk make_pair
                #define fi first
                #define se second
                #define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
                #define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
                #define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
                #define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
                using namespace std;
                 
                typedef long long int ll;
                typedef vector<int> vi;
                typedef vector<ll> vll;
                typedef pair<int,int> pi;
                typedef pair<ll,ll> pll;
                 
                const int N = 1e5+5;
                const ll ma = 1e19;
                ll h[N], r[N], w, l;
                int order[N];
                int cal_order(ll k)
                {
                	int x = 0;
                	while(k)
                	{
                		x++;
                		k /= 10;
                	}
                	return x;
                }
                ll cal(int n, ll x)
                {
                	priority_queue<ll> pq;
                	int ww = cal_order(x);
                	f(i,0,n)
                	{
                		ll k = h[i] + r[i] * x;
                		if(ww + order[i] > 18)
                			return ma;
                		if(k < 0)
                			return ma;
                		//trace2(i,k);
                		pq.push(k);
                	}
                	ll sum = 0;
                	while(!pq.empty() && pq.top() >= l)
                	{
                		sum += pq.top();
                		//trace2(pq.top(),sum);
                		pq.pop();
                	}
                	if(sum < 0)
                		sum = ma;
                	return sum;
                }
                ll binary_searc(int n, ll low, ll high)
                {
                	if(low  + 1 >= high)
                		return high;
                	ll mid = (low + high) / 2;
                	//trace5(low,high,mid,cal(n, mid),l);
                	ll sum = cal(n, mid);
                	if(sum <= w)
                		return binary_searc(n, mid, high);
                	else
                		return binary_searc(n, low, mid);
                }
                int main()
                {
                	int n;
                	scanf("%d %lld %lld",&n,&w,&l);
                	ll x = 0;
                	f(i,0,n)
                	{
                		scanf("%lld %lld",&h[i],&r[i]);
                		if(h[i] >= l)
                			x += h[i];
                		order[i] = cal_order(r[i]);
                	}
                	if(x >= w)
                		printf("0\n");
                	else
                	{
                		x = binary_searc(n, 0, ma);
                		ll j = x, ans = x, i = x;
                		while(cal(n, j) >= w)
                		{
                			ans = j;
                			j--;
                		}
                		if(cal(n, x) < w)
                		{
                			i = x + 1;
                			ans = x + 1;
                			while(cal(n, i) < w)
                			{
                				ans = i;
                				i++;
                			}
                		}
                		printf("%lld\n", ans);
                	}
                    return 0;
                }
