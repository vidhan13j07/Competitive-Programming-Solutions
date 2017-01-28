#include<bits/stdc++.h>
    #define ll long long int
    #define sc(v) v.size()
    #define eb push_back
    #define pb pop_back
    #define stl(a,it) for(auto it: a)
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define TC() int t;sf(t);while(t--)
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
     
    struct trie
    {
            ll c;
            ll node[12500000][2];
            
            void init()
            {
                c=1;
                node[0][0]=node[0][1]=-1;
            }
            
            void insert(ll v)
            {
                //cout<<endl<<"insert "<<v<<endl;
                ll temp=0;
                for(int i=31;i>=0;i--)
                {
                    ll next=(v&(1<<i))!=0;
                    if(node[temp][next]==-1)
                    {
                        //trace4(temp,next,node[temp][next],c);
                        //cout<<temp<<" "<<next<<" "<<node[temp][next]<<" "<<c<<endl;
                        node[temp][next]=c;
                        node[c][0]=node[c][1]=-1;
                        c++;
                    }
                    temp=node[temp][next];
                }
            }
            
            ll query(ll v)
            {
                //cout<<endl<<"query "<<v<<endl;
                ll temp=0,ans=0;
                for(int i=31;i>=0;i--)
                {
                    ll next=(v&(1<<i))!=0;
                    bool ok=true;
                    //cout<<temp<<" "<<next<<" "<<node[temp][next^1]<<" ";
                    if(node[temp][next^1]==-1)
                    {
                        ok=false;
                        next^=1;
                    }
                    //cout<<next<<" "<<ok<<endl;
                    if(ok)
                        ans+=(ll)(1<<i);
                    if (node[temp][next ^ 1] == -1)while(true) {}
                    temp=node[temp][next^1];
                }
                return ans;
            }
    };
    trie tree;
    int main() 
    {
        //ios_base::sync_with_stdio(false);cin.tie(NULL);
        const int N=400005;
        int ar[N];
        ll left[N],right[N];
        int n;
        scanf("%d",&n);
        //cin>>n;
        f(i,0,n)
            scanf("%lld",&ar[i]);
            //cin>>ar[i];
        tree.init();
        tree.insert(0);
        ll ma=0,x=0;
        f(i,0,n)
        {
            x^=ar[i];
            tree.insert(x);
            ma=max(ma,tree.query(x));
            //ma=max(ma,trie.query(0));
            left[i]=ma;
        }
        /*f(i,0,n)
            cout<<left[i]<<" ";
        cout<<endl;*/
        //left[n-1]=ar[n-1];
        tree.init();
        tree.insert(0);
        ma=0,x=0;
        for(int i=n-1;i>=0;i--)
        {
            x^=ar[i];
            tree.insert(x);
            ma=max(ma,tree.query(x));
            //ma=max(ma,trie.query(0));
            right[i]=ma;
        }
        /*for(int i=0;i<n;i++)
            cout<<right[i]<<" ";
        cout<<endl;*/
        //right[0]=ar[i];
        int i=0;
        ll ans=0;
        while(i<n-1)
        {
            ans=max(ans,left[i]+right[i+1]);
            i++;
        }
        printf("%lld\n",ans);
        return 0;
    }
