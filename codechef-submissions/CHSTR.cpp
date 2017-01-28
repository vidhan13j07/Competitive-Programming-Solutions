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
#define N 200010
#define MOD 1000000007
using namespace std;
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
struct node
{
	int ch[26],fail,len,v;
	void init()
	{
		memset(ch,0,sizeof(ch));
		fail=-1;len=0;v=1;
	}
}t[N*10];
int id[N*10],sz,n;
vector<int> v;
ll cnt[N*10],ans[N],cntA[5005];
char s[N];
bool cmp(int i,int j)
{
	return t[i].len>t[j].len;
}
void suffix()
{
	int i,j,ca=0,k,ed=0;
	t[0].init();
	sz=0;
	for(i=0;s[i];i++)
	{
		j=s[i]-'a';
		int p=++sz;
		t[p].init();
		t[p].len=t[ed].len+1;
		while(ed>=0&&!t[ed].ch[j])
			t[ed].ch[j]=p,ed=t[ed].fail;
		if(ed==-1)
		{
			t[p].fail=0;
			ed=p;
			continue;
		}
		int q=t[ed].ch[j];
		if(t[q].len==t[ed].len+1)
			t[p].fail=q;
		else
		{
			int r=++sz;
			t[r]=t[q];
			t[r].len=t[ed].len+1;
			t[p].fail=t[q].fail=r;
			t[r].v=0;
			while(ed>=0&&t[ed].ch[j]==q)
				t[ed].ch[j]=r,ed=t[ed].fail;
		}
		ed=p;
	}
	for(i=0;i<=sz;i++)
		id[i]=i,cnt[i]=0;
	for(i=0;i<=n;i++)
		ans[i]=0;
	sort(id,id+sz+1,cmp);
	for(k=0;k<=sz;k++)
	{
		i=id[k];
		if(t[i].v)
			cnt[i]++;
		j=t[i].fail;
		ll v=(ll)(t[i].len-t[j].len)*cnt[i];
		ans[1]+=v;
		if(cnt[i]+1<=n)
			ans[cnt[i]+1]-=v;
		cnt[j]+=cnt[i];
	}
	for(i=1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		cntA[i]=ans[i];
	}
	for(i=2;i<n;i++)
        cntA[i]=cntA[i]-cntA[i+1];
    v.clear();
    for(int i=2;i<=n;i++)
    {
        cntA[i]/=i;
        if(cntA[i])
            v.eb(i);
    }
}
ll power(ll a,ll b)
{
    ll x=1;
    while(b)
    {
    	if(b&1)
    		x*=a;
    	if(x>MOD)
    		x%=MOD;
    	a*=a;
    	if(a>MOD)
    		a%=MOD;
    	b>>=1;
    }
    return x;
}
 
int main()
{
	std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    static ll ncr[5001][5001] = {0};
    ll INV[5005];
    int i,j,k;
    for(int i=0;i<=5000;i++)
    {
    	INV[i] = power(i,MOD-2);
        ncr[i][0] = 1;
        ncr[0][i] = 1;
    }
    for(i=1;i<=5000;i++)
    {
        for(j=1;j<(i+2)/2;j++)
            ncr[i][j] = ((ncr[i][j-1]* (i-j+1))%MOD * INV[j])%MOD;
        k=j-1;
        if(i%2==0)
        	k--;
        for(;j<=i;j++,k--)
        	ncr[i][j]=ncr[i][k];
    }
    /*for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=10;j++)
        {
            cout<<ncr[i][j]<<" ";
        }
        cout<<endl;
    }*/
 
    int t,temp,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        scanf("%s",s);
        suffix();
       /* for(int i=0;i<strlen(s);i++)
        {
            cout<<cntA[i]<<" ";
        }
        cout<<endl;*/
        ll ans[5005] = {0},sum;
        ans[1] = cntA[1];
        for(int i=2;i<=n;i++)
        {
            //cout<<cntA[i]<<" ";
            sum = 0;
            for(int ind=0;ind<v.size();ind++)
            {
                j = v[ind];
                //cout<<j<<" "<<i<<endl;
                sum = (sum + (cntA[j] * ncr[j][i]))%MOD;
            }
           // cout<<"sum: "<<sum<<endl;
            ans[i] = sum;
        }
        /*for(int i=1;i<=n;i++)	
        	cout<<ans[i]<<" ";
        cout<<endl;*/
        while(q--)
        {
            scanf("%d",&temp);
            if(temp <= n)
            	printf("%lld\n",ans[temp]);
            else
            	printf("0\n");
        }
    }
    return 0;
}
