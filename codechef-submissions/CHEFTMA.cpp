#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e5+5;
int diff[N],balls[2*N];
int main() 
{
	int t,n,m,k,temp;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&diff[i]);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			diff[i]-=temp;
		}
		for(int i=0;i<m+k;i++)
			scanf("%d",&balls[i]);
		sort(diff,diff+n);
		sort(balls,balls+m+k);
		int end=m+k;
		ans=0;
		for(int i=n-1;i>=0;i--)
		{
			int ind=(upper_bound(balls,balls+end,diff[i])-balls)-1;
			if(ind==-1)
				ans+=diff[i];
			else
				ans+=diff[i]-balls[ind];
			end=ind;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
