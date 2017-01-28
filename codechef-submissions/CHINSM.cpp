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
    //void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
    //TEMPLATE ENDS HERE
    const int N=1e5+5;
    vi val(N,0);
    int ri[N];
    int ar[N];
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
    inline void readl(ll *a)
    {
        register char c=0;
        while (c < 33)
    		c = gc();
    	*a = 0;	
    	while (c > 33)
        {
    		*a = *a * 10 + c - '0';
    		c = gc();
    	}
    }
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
    int chk(int a,int b)
    {
        int temp=a/b;
        return a-(temp*b);
    }
    int main() 
    {
        //FastIO();
        int n,k;
        ll ans=0;
        readc(n);readc(k);
        //cout<<n<<" "<<k<<endl;
        f(i,0,n)
            readc(ar[i]);
        S[0].id = n + 1;
        int top = 0;
        for (int i = n-1; i>=0; i--)
        {
            while (top and S[top].v <= ar[i])
                top--;
            ri[i] = S[top].id;
            S[++top] = Maxi(ar[i], i);
        }
        /*f(i,0,n)
            trace3(i,ar[i],ri[i]);*/
        /*f(i,0,n)
            cout<<ar[i]<<" ";*/
        /*int i=n-1,j,pos=n;
        while(i>=0)
        {
            //cout<<i<<endl;
            if(ar[i]<k)
                ans+=(ll)(pos-i);
            else
            {
                j=i+1;
                while(j<pos)
                {
                    if(chk(ar[i],ar[j])==k)
                    {
                        pos=j;
                        break;
                    }
                    j++;
                }
                ans+=(ll)(j-i);
            }
            i--;
        }*/
        int i=n-1,j,pos=n;
        //cout<<i<<" "<<pos<<endl;
        while(i>=0)
        {
            if(ar[i]==k)
            {
                if(ri[i]<pos)
                    pos=ri[i];
            }
            else if(ar[i]>k)
            {
                int temp=ar[i]-k;
                j=1;
                while(j<=(int)(sqrt(temp)))
                {
                    if(chk(temp,j)==0)
                    {
                        if(j>k and val[j]>0 and val[j]<pos)
                            pos=val[j];
                        int temp1=temp/j;
                        if(temp1>k and val[temp1]>0 and val[temp1]<pos)
                            pos=val[temp1];
                    }
                    j++;
                }
            }
            ans+=(ll)(pos-i);
            //cout<<i<<" "<<ans<<" "<<pos<<endl;
            val[ar[i]]=i;
            i--;
        }
        //ans+=n;
        printf("%lld\n",ans);
        return 0;
    }
