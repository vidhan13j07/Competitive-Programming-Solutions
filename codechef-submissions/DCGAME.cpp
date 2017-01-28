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
#define endl "\n"
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
#define gc getchar_unlocked
using namespace std;
inline void readc(int &x)
{
    register int c = gc();
	x = 0;
	int neg = 0;
    for(; ((c<48 || c>57) && c != '-');c=gc())
		;
	if(c=='-')
	{
		neg = 1;
		c = gc();
	}
	for(; c>47 && c<58 ; c = gc()) {
		x = (x<<1) + (x<<3) + c - 48;
	}
	if(neg)
    	x = -x;
}
inline void readl(ll *a) {
    register char c=0;
	while (c < 33)
		c = gc();
	*a = 0;	
	while (c > 33) {
		*a = *a * 10 + c - '0';
		c = gc();
	}
}
//void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
const int N=1e6+5;
ll ar[N],c[N];
ll le[N],ri[N];
vector < pair<ll,ll> > vp;
class Maxi
{
    public:
        ll v;
        int id;
        Maxi() {}
        Maxi(ll v, int id)
        {
            this->v = v;
            this->id = id;
        }
} S[N];
int main() 
{
    //FastIO();
    ll n,q,temp;
    ll s;
    char ch1,ch2;
    readl(&n);readl(&q);
    f(i,1,n+1)
        readl(&ar[i]);
    S[0].id = 0;
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top and S[top].v<ar[i])
            top--;
        le[i] = S[top].id;
        S[++top] = Maxi(ar[i],i);
    }
    S[0].id = n + 1;
    top = 0;
    for (int i = n; i >= 1; i--)
    {
        while (top and S[top].v <= ar[i])
            top--;
        ri[i] = S[top].id;
        S[++top] = Maxi(ar[i], i);
    }
    for(int i=1;i<=n;i++)
    {
        temp=((i - le[i])*(ri[i] - i));
        vp.eb(mk(ar[i],temp));
    }
    sort(vp.begin(),vp.end());
    temp=0;
    int len,i;
    ar[0]=vp[0].fi;
    c[0]=vp[0].se;
    for(i=1,len=0;i<n;i++)
    {
        if(vp[i].fi==ar[len])
            c[len]+=vp[i].se;
        else
        {
            len++;
            ar[len]=vp[i].fi;
            c[len]=vp[i].se;
        }
    }
    f(i,0,len+1)
    {
        ll temp1=((n*(n+1))/2)-temp;
        ri[i]=temp1;
        temp+=c[i];
        le[i]=temp;
    }
    /*f(i,0,len+1)
        trace4(ar[i],c[i],le[i],ri[i]);*/
    while(q--)
    {
        s=0;
        scanf(" %c%lld %c",&ch1,&temp,&ch2);
        //printf("%c %lld %c\n",ch1,temp,ch2);
        if(ch1=='>')
        {
            if(temp>=ar[len])
                s=0;
            else if(temp<ar[0])
                s=(n*(n+1))/2;
            else
            {
                int low=0,high=len,mid;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    if(ar[mid-1]<=temp and ar[mid]>temp)
                        break;
                    else if(ar[mid]>temp)
                        high=mid-1;
                    else
                        low=mid+1;
                }
                s=ri[mid];
                if(temp==ar[mid])
                    s-=c[mid];
                //cout<<temp<<" "<<ar[mid]<<" "<<s<<endl;
            }
            //cout<<s<<endl;
        }
        else if(ch1=='<')
        {
            if(temp<=ar[0])
                s=0;
            else if(temp>ar[len])
                s=(n*(n+1))/2;
            else
            {
                int low=0,high=len,mid;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    //cout<<mid<<endl;
                    if(ar[mid]<temp and ar[mid+1]>=temp)
                        break;
                    else if(ar[mid]>=temp)
                        high=mid-1;
                    else
                        low=mid+1;
                }
                s=le[mid];
            }
            //cout<<s<<endl;
        }
        else
        {
            if(temp<ar[0] or temp>ar[len])
                s=0;
            else
            {
                int found=-1;
                int low=0,high=len;
                while(low<=high)
                {
                    int mid=(low+high)/2;
                    //cout<<mid<<endl;
                    if(ar[mid]==temp)
                    {
                        found=mid;
                        break;
                    }
                    else if(ar[mid]>temp)
                        high=mid-1;
                    else
                        low=mid+1;
                }
                //cout<<found<<endl;
                if(found!=-1)
                    s=c[found];
                else
                    s=0;
                //cout<<"\ns="<<s<<endl;
            }
        }
        //cout<<s<<" ";
        if(s%2==1)
            printf("%c",ch2);
        else
        {
            if(ch2=='D')
                printf("C");
            else
                printf("D");
        }
    }
    return 0;
}
