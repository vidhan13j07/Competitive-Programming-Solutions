#include<bits/stdc++.h>
                #define ll long long int
                #define sc(v) v.size()
                #define eb push_back
                #define pb pop_back
                #define stl(a,it) for(auto it: a)
                #define f(i,a,b) for(int i=a;i<b;i++)
                #define TC() int t;cin>>t;while(t--)
                #define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
                #define mk make_pair
                #define fi first
                #define se second 
                #define trace1(x)                cout <<#x<<": "<<x<<endl;
                #define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
                #define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
                #define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
                #define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
                #define mem(a,b) memset(a,b,sizeof(a))
                #define vi vector<int>
                #define vll vector<ll>
                #define pi pair<int,int>
                #define pll pair<ll,ll>
                using namespace std;
                const int N=1e5+5;
                pi ar[3*N];
                int k;
                vi v;
                vector< pi > vp,temp;
                map<int,int> mp;
                void cal(int s)
                {
                	int n;
                	temp.clear();
                	sort(vp.begin(),vp.end());
                	n=sc(vp)/3;
                	bool vis[3*n+5];
                	f(i,0,3*n+5)
                		vis[i]=0;
                	int i=0,j=3*n-1;
                	while(i<j)
                	{
                		while(vis[i])
                			i++;
                		while(vis[j])
                			j--;
                		int x=s-(vp[i].fi+vp[j].fi);
                		int id = std::lower_bound(vp.begin(),vp.end(),pi(x,std::numeric_limits<int>::min()))-vp.begin();
                		if(id>=0 and id<3*n and vp[id].fi==x and !vis[id] and id!=i and id!=j and i!=j)
                		{
                			vis[id]=1;
                			vis[i]=1;
                			vis[j]=1;
                			v.eb(vp[i].se);
                			v.eb(vp[j].se);
                			v.eb(vp[id].se);
                			k++;
                		}
                		i++;
                		j--;
                	}
                	i=0,j=(3*n)/2;
                	while(j<3*n)
                	{
                		while(vis[i])
                			i++;
                		while(vis[j])
                			j++;
                		if(i==3*n or j==3*n)
                			break;
                		int x=s-(vp[i].fi+vp[j].fi);
                		int id = std::lower_bound(vp.begin(),vp.end(),pi(x,std::numeric_limits<int>::min()))-vp.begin();
                		if(id>=0 and id<3*n and vp[id].fi==x and !vis[id] and id!=i and id!=j and i!=j)
                		{
                			vis[id]=1;
                			vis[i]=1;
                			vis[j]=1;
                			v.eb(vp[i].se);
                			v.eb(vp[j].se);
                			v.eb(vp[id].se);
                			k++;
                		}
                		i++;
                		j++;
                	}
                	i=(3*n)/2,j=(3*n)/2;
                	//i=0,j=(3*n)/2;
                	while(i>=0 and j<3*n)
                	{
                		while(vis[i])
                			i--;
                		while(vis[j])
                			j++;
                		if(i==-1 or j==3*n)
                			break;
                		int x=s-(vp[i].fi+vp[j].fi);
                		int id = std::lower_bound(vp.begin(),vp.end(),pi(x,std::numeric_limits<int>::min()))-vp.begin();
                		if(id>=0 and id<3*n and vp[id].fi==x and !vis[id] and id!=i and id!=j and i!=j)
                		{
                			vis[id]=1;
                			vis[i]=1;
                			vis[j]=1;
                			v.eb(vp[i].se);
                			v.eb(vp[j].se);
                			v.eb(vp[id].se);
                			k++;
                		}
                		i++;
                		j++;
                	}
                	f(i,0,3*n)
                		if(!vis[i])
                			temp.eb(vp[i]);
                }
                int main() 
                {
                	int n,ma=0,s;
                	mp.clear();
                	v.clear();
                	k=0;
                	scanf("%d",&n);
                	f(i,0,3*n)
                	{
                		scanf("%d",&ar[i].fi);
                		ar[i].se=i;
                	}
                	sort(ar,ar+3*n);
                	f(i,0,n)
                	{
                		int x=ar[i].fi+ar[n+i].fi+ar[3*n-i-1].fi;
                		//trace2(i,x);
                		if(mp.find(x)==mp.end())
                			mp[x]=1;
                		else
                			mp[x]++;
                	}
                	for(auto it:mp)
                		if(it.se>ma)
                		{
                			s=it.fi;
                			ma=it.se;
                		}
                	f(i,0,n)
                	{
                		int x=ar[i].fi+ar[n+i].fi+ar[3*n-i-1].fi;
                		if(x==s)
                		{
                			v.eb(ar[i].se);
                			v.eb(ar[n+i].se);
                			v.eb(ar[3*n-i-1].se);
                			k++;
                		}
                		else
                		{
                			temp.eb(ar[i]);
                			temp.eb(ar[n+i]);
                			temp.eb(ar[3*n-i-1]);
                		}
                	}
                	f(i,0,175)
                	{
                		vp.clear();
            	  		for(auto it:temp)
                			vp.eb(it);
                		cal(s);
                	}
                	printf("%d\n",k);
                	for(auto it:v)
                		printf("%d ",it+1);
                	printf("\n");
                	return 0;
                }
