#include<bits/stdc++.h>
    #define ll long long int
    #define scx(v) v.size()
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
    #define gc getchar_unlocked
    using namespace std;
    //Dynamic Convex hull trick 
    //References https://github.com/niklasb/contest-algos/blob/master/convex_hull/dynamic.cpp#L1
    const ll is_query = -(1LL<<62);
    const ll N=5e4+5;
    inline void sc(int &x)
    {
    	register int c = gc();
	    x = 0;
    	int neg = 0;
    	for(; ((c<48 || c>57) && c != '-'); 
    		c = gc());
    	if(c=='-')
    	{
    		neg = 1;
    		c = gc();
    	}
    	for(; c>47 && c<58 ; c = gc())
    		x = (x<<1) + (x<<3) + c - 48;
 		if(neg)
    		x = -x;
	}
    class Line 
    {
    	public:
    	    mutable function<const Line*()> succ;
    	    ll m,b;
    	    //Line *s;
        	bool operator<(const Line& l) const 
        	{
            	if (l.b!=is_query)
            		return m<l.m;
            	const Line* s = succ();
        	    if (!s)
            		return 0;
            	ll t=l.m;
            	return b-s->b<(s->m-m)*t;
        	}
    };
    
    int tim[N],speed[N];
    multiset<Line> h;
    ll ar[N];
    void add(ll,ll);
    bool chk(std::multiset<Line>::iterator);
    
    int main() 
    {
    	int n,q,type,t,s,ind;
    	//scanf("%d %d",&n,&q);
    	sc(n);sc(q);
    	while(q--)
    	{
    		//scanf("%d %d",&type,&t);
    		sc(type);sc(t);
    		if(type==1)
    		{
    			sc(ind);sc(s);
    			//scanf("%d %d",&ind,&s);
    			ar[ind]+=speed[ind]*(ll)(t-tim[ind]);
    			add(s,ar[ind]-(ll)t*s);
    			speed[ind]=s;
    			tim[ind]=t;
    			continue;
    		}
    		Line x;
    		x.m=t;
    		x.b=is_query;
    		auto l = h.lower_bound(x);
    		printf("%lld\n",t*l->m+l->b);
    	}
    	return 0;
    }
    
    void add(ll m, ll b)
    {
    	Line x;
    	x.m=m;x.b=b;
        std::multiset<Line>::iterator l = h.insert(x);
        l->succ = [=] { return next(l) == h.end() ? 0 : &*next(l); };
        if (chk(l))
        {
            h.erase(l);
            return;
        }
        while (l!=h.begin() and chk(prev(l)))
         	h.erase(prev(l));
        while (next(l) != h.end() and chk(next(l)))
            h.erase(next(l));
    }
    
    bool chk(std::multiset<Line>::iterator y)
    {   
    	double i,j;
        std::multiset<Line>::iterator z = next(y);
        if (y == h.begin())
        {
            if (z == h.end())
                return 0;
            return y->m == z->m && y->b <= z->b;
        }
        std::multiset<Line>::iterator x = prev(y);
        if (z == h.end())
        	return y->m == x->m && y->b <= x->b;
        i=(1.0*(x->b-y->b))/(y->m-x->m);
        j=(1.0*(y->b-z->b))/(z->m-y->m);
        return i>=j;
    }
