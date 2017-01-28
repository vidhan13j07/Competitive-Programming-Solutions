#include<bits/stdc++.h>
        #define ll long long int
        using namespace std;
        const int N=1e5+5;
        const ll mod=1e9+7;
        ll dp[N],cnt[10],power2[8];
        pair<int,int> p[8];
        map<int,int> e,s;
        map<int, vector<int> > mp;
        ll find(int n,int m,int mask)
        {
        	int c=0;
        	e.clear();
        	s.clear();
        	mp.clear();
        	//map<int,int> e,s;
        	//map<int, vector<int> > mp;
        	for(int i=0;i<m;i++)
        		if(mask&(1<<i))
        		{
        			int a=p[i].first,b=p[i].second;
        			if(e.find(a)!=e.end())
        				e[a]++;
        			else
        				e[a]=1;
        			if(e.find(b)!=e.end())
        				e[b]++;
        			else
        				e[b]=1;
        			if(e[a]>2 or e[b]>2)
        				return 0;
        			if(s.find(a)==s.end() and s.find(b)==s.end())
        			{
        				c++;
        				s[a]=c;
        				s[b]=c;
        				mp[c].push_back(a);
        				mp[c].push_back(b);
        			}
        			else if(s.find(a)==s.end())
        			{
        				s[a]=s[b];
        				mp[s[b]].push_back(a);
        			}
        			else if(s.find(b)==s.end())
        			{
        				s[b]=s[a];
        				mp[s[a]].push_back(b);
        			}
        			else if(s[a]!=s[b])
        			{
        				/*cout<<"here "<<mask<<"\n";
        				cout<<p[i].first<<" "<<p[i].second<<endl;
        				cout<<"***************************************\n";
        				for(auto i:mp)
        				{
        					cout<<"X "<<i.first<<endl;
        					for(auto j: i.second)
        						cout<<j<<" ";
        					cout<<endl;
        				}
        				cout<<endl;*/
        				int j=s[a],k=s[b];
        				for(int v=0;v<mp[k].size();v++)
        				{
        					s[mp[k][v]]=j;
        					mp[j].push_back(mp[k][v]);
        				}
        				mp.erase(k);
        				s.erase(k);
        				/*for(auto x:mp[k])
        				{
        					s[x]=s[a];
        					mp[s[a]].push_back(x);
        				}
        				mp.erase(s[b]);
        				s.erase(s[b]);*/
        				/*for(auto i:mp)
        				{
        					cout<<"X "<<i.first<<endl;
        					for(auto j: i.second)
        						cout<<j<<" ";
        					cout<<endl;
        				}
        				cout<<"****************************\n";*/
        			}
        		}
        	/*if(mask==7)
        	{
        		for(auto i:mp)
        		{
        			cout<<"X "<<i.first<<endl;
        			for(auto j: i.second)
        				cout<<j<<" ";
        			cout<<endl;
        		}
        		cout<<endl;
        	}*/
        	c=0;
        	for(auto i:mp)
        	{
        		c++;
        		n+=2-i.second.size();
        		int l=0;
        		for(auto it:i.second)
        			if(e[it]==3)
        				return 0;
        			else if(e[it]==1)
        				l++;
        		if(l!=2)
        			return 0;
        	}
        	if(n<c)
        		return 0;
        	ll x=dp[n-c]*power2[c];
        	if(x>=mod)
        		x%=mod;
        	//cout<<mask<<" "<<c<<" "<<n<<" "<<x<<endl;
        	return x;
        }
        int main() 
        {
        	int t,n,m;
        	ll ans;
        	dp[0]=1;
        	power2[0]=1;
        	for(int i=1;i<N;i++)
        	{
        		dp[i]=i*dp[i-1];
        		if(dp[i]>=mod)
        			dp[i]%=mod;
        	}
        	for(int i=1;i<8;i++)
        	{
        		power2[i]=2*power2[i-1];
        		if(power2[i]>=mod)
        			power2[i]%=mod;
        	}
        	scanf("%d",&t);
        	while(t--)
        	{
        		scanf("%d %d",&n,&m);
        		cnt[0]=0;
        		for(int i=0,k=0;i<m;i++)
        		{
        			scanf("%d %d",&p[k].first,&p[k].second);
        			if(p[k].first>p[k].second)
        				swap(p[k].first,p[k].second);
        			//assert(p[i].first==p[i].second);
        			cnt[i+1]=0;
        			k++;
        			if(i==m-1)
        				m=k;
        		}
        		//sort(p,p+n);
        		/*if(n==10)
        		{
        			for(int i=0;i<n;i++)
        				cnt[i]=i+1;
        			ans=0;
        			do
        			{
        				bool chk=1;
        				for(int i=0;i<m;i++)
        				{
        					for(int j=0;j<n;j++)
        						if(p[i].first==cnt[j])
        						{
        							if(j>=1 and p[i].second==cnt[j-1])
        								chk=0;
        							if(j+1<n and p[i].second==cnt[j+1])
        								chk=0;
        							if(!chk)
        								break;
        						}
        					if(!chk)
        						break;
        				}
        				if(chk)
        					ans++;
        			}while(next_permutation(cnt,cnt+n));
        			printf("%lld\n",ans);
        			continue;
        		}*/
        		for(int i=1;i<(1<<m);i++)
        		{
        			ll x=find(n,m,i);
        			int c=0,temp=i;;
        			while(temp)
        			{
        				if(temp&1)
        					c++;
        				temp>>=1;
        			}
        			//cout<<i<<" "<<c<<" "<<x<<" "<<cnt[c]<<endl;
        			cnt[c]+=x;
        			if(cnt[c]>=mod)
        				cnt[c]%=mod;
        		}
        		/*cout<<dp[n]<<" ";//1064160
        		for(int i=1;i<m;i++)
        			cout<<cnt[i]<<" ";
        		cout<<endl;*/
        		ans=dp[n];
        		for(int i=0;i<=m;i++)
        			if(i&1)
        				ans=(ans+mod-cnt[i])%mod;
        			else
        			{
        				ans+=cnt[i];
        				if(ans>=mod)
        					ans%=mod;
        			}
        		printf("%lld\n",ans);
        	}
        	return 0;
        }
