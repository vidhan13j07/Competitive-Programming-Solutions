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
#define N 1005
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
 
vector < pair<int,int> > v;
vector < pair<int,int> > v1;
deque <int> d1;
deque <int> d2;
int mat[N][N];
int visit[N];
int ans[N];
int zero,one,n,z;
int c[N];
int temp[N];
 
void cal(int k)
{
	if(c[k])
		return;
	d1.clear();
	d2.clear();
	c[k]=1;
	d1.eb(k);
	int count=0;
	while(!d1.empty())
	{
		k=d1.front();
		d2.eb(k);
		count++;
		d1.pop_front();
		f(i,1,n+1)
			if(!c[i] and mat[k][i])
			{
				c[i]=1;
				d1.eb(i);
			}
	}
	if(count<=1)
		return;
	while(!d2.empty())
	{
		k=d2.front();
		v[k].second=count;
		d2.pop_front();
	}
}
 
void place(int ind,int val)
{
	if(visit[ind])
		return;
	visit[ind]=1;
	temp[ind]=z;
	ans[ind]=val;
	f(j,1,n+1)
		if(mat[ind][j])
		{
			ans[j]=ans[ind]^1;
			place(j,ans[j]);
			visit[j]=1;
		}
}
 
void place1(int ind,int val)
{
	if(visit[ind])
		return;
	visit[ind]=1;
	ans[ind]=val;
	if(ans[ind])
		one++;
	else
		zero++;
	f(j,1,n+1)
		if(mat[ind][j])
		{
			ans[j]=ans[ind]^1;
			if(ans[j])
				one++;
			else
				zero++;
			place1(j,ans[j]);
			visit[j]=1;
		}
}
 
int main() 
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	bool flag;
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();
		v1.clear();
		flag=true;
		v.eb(mk(0,0));
		f(i,1,n+1)
		{
			v.eb(mk(i,0));
			ans[i]=-1;
			visit[i]=0;
			c[i]=0;
			temp[i]=0;
		}
		/*f(i,1,n+1)
			cout<<v[i].first<<" "<<v[i].second<<endl;*/
		f(i,1,n+1)
			f(j,1,n+1)
			{
				cin>>mat[i][j];
				if(mat[i][j])
				{
					if(i==j)
						flag=0;
					if(i<j)
					{
						v1.eb(mk(i,j));
					//	v[i].second++;
					//	v[j].second++;
					}
				}
			}
		/*f(i,1,n+1)
			cout<<v[i].first<<" "<<v[i].second<<endl;*/
		if(flag)
		{
			//f(i,0,n+1)
			//	cout<<v[i].first<<" "<<v[i].second<<endl;
			//cout<<"a"<<endl;
			f(i,1,n+1)
				cal(i);
			sort(v.rbegin(),v.rend(),sort_pair_second<int,int>());
			//f(i,0,n+1)
			//	cout<<v[i].first<<" "<<v[i].second<<endl;
			//cout<<sc(v)<<" "<<sc(v1)<<endl;
			int a=0,b=0;
			f(i,0,n+1)
			{
				if(v[i].second>0)
				{
					if(a>b)
						place(v[i].first,1);
					else
						place(v[i].first,0);
				}
				else
					break;
				zero=0,one=0;
				f(j,1,n+1)
					if(temp[j]==z)
					{
						if(ans[j]==0)
							zero++;
						else if(ans[j]==1)
							one++;
					}
				if(a>b)
				{
					if(zero>one)
					{
						f(j,1,n+1)
							if(temp[j]==z)
								ans[j]^=1;
						b+=zero;
						a+=one;
					}
					else
					{
						a+=zero;
						b+=one;
					}
				}
				else
				{
					if(zero<=one)
					{
						f(j,1,n+1)
							if(temp[j]==z)
								ans[j]^=1;
						b+=zero;
						a+=one;
					}
					else
					{
						a+=zero;
						b+=one;
					}
				}
				z++;
			}
			/*f(i,1,n+1)
				cout<<i<<" "<<ans[i]<<endl;*/
			one=0,zero=0;
			f(i,1,n+1)
				if(ans[i]==0)
					zero++;
				else if(ans[i]==1)
					one++;
			//cout<<zero<<" "<<one<<endl;
			f(i,1,n+1)
				if(ans[i]==-1)
					if(zero>one)
					{
						ans[i]=1;
						one++;
					}
					else
					{
						ans[i]=0;
						zero++;
					}
			f(i,0,sc(v1))
				if(ans[v1[i].first]==ans[v1[i].second])
					flag=0;
			zero=0,one=0;
			f(i,1,n+1)
				if(ans[i]==0)
					zero++;
				else if(ans[i]==1)
					one++;
			if(abs(zero-one)>=2)
			{
				f(i,1,n+1)
				{		
					ans[i]=-1;
					visit[i]=0;
				}
				zero=0,one=0,a=0;
				f(i,0,n+1)
				{
					if(v[i].second>0)
						place1(v[i].first,a);
					else
						break;
					if(zero>one)
						a=1;
					else
						a=0;
				}
			/*f(i,1,n+1)
				cout<<i<<" "<<ans[i]<<endl;*/
				one=0,zero=0;
				f(i,1,n+1)
					if(ans[i]==0)
						zero++;
					else if(ans[i]==1)
						one++;
			//cout<<zero<<" "<<one<<endl;
				f(i,1,n+1)
					if(ans[i]==-1)
						if(zero>one)
						{
							ans[i]=1;
							one++;
						}
						else
						{
							ans[i]=0;
							zero++;
						}
				f(i,0,sc(v1))
					if(ans[v1[i].first]==ans[v1[i].second])
						flag=0;
			}
		}
		if(flag)
		{
			f(i,1,n+1)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
