#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1005;
ll sell[N][N],buy[N][N];
double counts[N][N],countb[N][N];
int main() 
{
	int n,m;
	bool fl=1;
	double d,ans,a=1.0*(1e18);
	scanf("%d %d %lf",&n,&m,&d);
	ans=d;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%lld %lld",&sell[i][j],&buy[i][j]);
			counts[i][j]=0.0;
			countb[i][j]=0.0;
		}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(j+1<m)
			{
				if(i+1<n)
				{
					counts[i+1][j+1]=max(counts[i+1][j+1],counts[i][j]);
					countb[i+1][j+1]=max(countb[i+1][j+1],countb[i][j]);
				}
				if(i>=1)
				{
					counts[i-1][j+1]=max(counts[i-1][j+1],counts[i][j]);
					countb[i-1][j+1]=max(countb[i-1][j+1],countb[i][j]);
				}
			}
			counts[i][j]=max(counts[i][j],d);
			counts[i][j]/=sell[i][j];
			countb[i][j]*=buy[i][j];
			if(j>=1)
			{
				counts[i][j]=max(counts[i][j],counts[i][j-1]);
				counts[i][j]=max(counts[i][j],countb[i][j-1]/sell[i][j]);
				countb[i][j]=max(countb[i][j],countb[i][j-1]);
				countb[i][j]=max(countb[i][j],counts[i][j-1]*buy[i][j]);
			}
			if(j+2<m)
			{
				if(i+1<n)
				{
					counts[i+1][j+2]=max(counts[i+1][j+2],countb[i][j]);
					countb[i+1][j+2]=max(countb[i+1][j+2],counts[i][j]);
				}
				if(i>=1)
				{
					counts[i-1][j+2]=max(counts[i-1][j+2],countb[i][j]);
					countb[i-1][j+2]=max(countb[i-1][j+2],counts[i][j]);
				}
			}
			if(countb[i][j]>a)
			{
				fl=0;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
		ans=max(ans,countb[i][m-1]);
	if(fl)
		printf("%0.6lf\n",ans);
	else
		printf("Quintillionnaire\n");
	return 0;
}
