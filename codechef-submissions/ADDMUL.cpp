#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define TC() int t;cin>>t;while(t--)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
#define endl "\n"
#define fi first
#define se second 
#define gcd __gcd
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define chk(a) if(a>=mod) a%=mod;
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
}
void die()
{
    cout<<"0"<<endl;
    exit(0);
}
ll power(ll a,ll b)
{
    ll x=1;
    while(b)
    {
        if(b&1)
            x*=a;
        a*=a;
        chk(x);
        chk(a);
        b>>=1;
    }
    return x;
}
//TEMPLATE ENDS HERE
const int N=1e5+5;
const int K=4*N+5;
ll ar[N],val[K],lazyadd[K],lazymul[K];
bool flag[K];
void init()
{
    f(i,0,K)
    {
        lazyadd[i]=0;
        lazymul[i]=0;
        flag[i]=0;
    }
}
int middle(int a,int b)
{
    return (a+b)/2;
}
void build(int i,int a,int b)
{
    if(a>b)
        return ;
    if(a==b)
    {
        val[i]=ar[a];
        return ;
    }
    int mid=middle(a,b);
    build(2*i+1,a,mid);
    build(2*i+2,mid+1,b);
    val[i]=val[2*i+1]+val[2*i+2];
    chk(val[i]);
}
void propagate(int i,int a,int b)
{
    if(flag[i])
        val[i]=((b-a+1)*lazyadd[i]);
    else
    {
        if(lazymul[i]!=0)
            val[i]*=lazymul[i];
        chk(val[i]);
        if(lazyadd[i]!=0)
            val[i]+=((b-a+1)*lazyadd[i]);
    }
    chk(val[i]);
    /*if(lazyadd[i]!=0)
      if(lazymul[i]==0)
      val[i]+=((b-a+1)*lazyadd[i]);
      else
      val[i]+=((b-a+1)*lazyadd[i]*lazymul[i]);
      else 
      if(lazymul[i]!=0)
      val[i]*=lazymul[i];
    //2,3,4=9
    //3*4*3=36
    //6,7,8=18,21,24=63-9=54*/
    //2,3,4=9
    //+3,*4,*2,+4,+3,*2
    //5,6,7=20,24,28=40,48,56=44,52,60=47,55,63=94,110,126
    //330
    //9*16+(3*16+7*2)*3=144+3*(48+14)=144+3*62=144+186=330
    if(a!=b)
    {
        if(flag[i])
        {
            flag[2*i+1]=1;
            flag[2*i+2]=1;
            lazyadd[2*i+1]=lazyadd[i];
            lazyadd[2*i+2]=lazyadd[i];
            lazymul[2*i+1]=lazymul[i];
            lazymul[2*i+2]=lazymul[i];
        }
        else
        {
            lazyadd[2*i+1]+=lazyadd[i];
            lazyadd[2*i+2]+=lazyadd[i];
            if(lazymul[i]!=0)
            {
                if(lazymul[2*i+1]==0)
                    lazymul[2*i+1]=1;
                if(lazymul[2*i+2]==0)
                    lazymul[2*i+2]=1;
                lazymul[2*i+1]*=lazymul[i];
                lazymul[2*i+2]*=lazymul[i];
            }
        }
        chk(lazyadd[2*i+1]);
        chk(lazyadd[2*i+2]);
        chk(lazymul[2*i+1]);
        chk(lazymul[2*i+2]);
    }
    lazyadd[i]=0;
    lazymul[i]=0;
    flag[i]=0;
}
void update1(int i,int a,int b,int l,int r,ll v)
{
    //cout<<"here"<<endl;
    propagate(i,a,b);
    if(a>b or a>r or b<l)
        return ;
    if(a>=l and b<=r)
    {
        val[i]+=((b-a+1)*v);
        chk(val[i]);
        if(a!=b)
        {
            lazyadd[2*i+1]+=v;
            lazyadd[2*i+2]+=v;
            chk(lazyadd[2*i+1]);
            chk(lazyadd[2*i+2]);
            //cout<<i<<" "<<2*i+1<<" "<<2*i+2<<endl;
        }
        return ;
    }
    int mid=middle(a,b);
    update1(2*i+1,a,mid,l,r,v);
    update1(2*i+2,mid+1,b,l,r,v);
    val[i]=val[2*i+1]+val[2*i+2];
    chk(val[i]);
}
void update2(int i,int a,int b,int l,int r,ll v)
{
    //cout<<"before propagate "<<i<<endl;
    propagate(i,a,b);
    //cout<<"after propagate "<<i<<endl;
    if(a>b or a>r or b<l)
        return ;
    //cout<<"after check "<<i<<" "<<a<<" "<<b<<" "<<l<<" "<<r<<endl;
    if(a>=l and b<=r)
    {
        //cout<<i<<" "<<val[i]<<" ";
        val[i]*=v;
        //cout<<val[i]<<endl;
        chk(val[i]);
        if(a!=b)
        {
            if(lazymul[2*i+1]==0)
                lazymul[2*i+1]=1;
            if(lazymul[2*i+2]==0)
                lazymul[2*i+2]=1;
            lazyadd[2*i+1]*=v;
            lazyadd[2*i+2]*=v;
            lazymul[2*i+1]*=v;
            lazymul[2*i+2]*=v;
            chk(lazymul[2*i+1]);
            chk(lazymul[2*i+2]);
            chk(lazyadd[2*i+1]);
            chk(lazyadd[2*i+2]);
        }
        return ;
    }
    int mid=middle(a,b);
    update2(2*i+1,a,mid,l,r,v);
    update2(2*i+2,mid+1,b,l,r,v);
    val[i]=val[2*i+1]+val[2*i+2];
    chk(val[i]);
}
void update3(int i,int a,int b,int l,int r,ll v)
{
    propagate(i,a,b);
    if(a>b or a>r or b<l)
        return ;
    if(a>=l and b<=r)
    {
        val[i]=((b-a+1)*v);
        chk(val[i]);
        if(a!=b)
        {
            lazyadd[2*i+1]=v;
            lazyadd[2*i+2]=v;
            lazymul[2*i+1]=0;
            lazymul[2*i+2]=0;
            flag[2*i+1]=1;
            flag[2*i+2]=1;
        }
        return ;
    }
    int mid=middle(a,b);
    update3(2*i+1,a,mid,l,r,v);
    update3(2*i+2,mid+1,b,l,r,v);
    val[i]=val[2*i+1]+val[2*i+2];
    chk(val[i]);
}
ll query(int i,int a,int b,int l,int r)
{
    propagate(i,a,b);
    if(a>r or a>b or b<l)
        return 0;
    if(a>=l and b<=r)
        return val[i];
    int mid=middle(a,b);
    return (query(2*i+1,a,mid,l,r)+query(2*i+2,mid+1,b,l,r))%mod;
}
int main() 
{
    FastIO();
    int n,q,temp,l,r;
    ll ans,v;
    cin>>n>>q;
    init();
    f(i,0,n)
        cin>>ar[i];
    build(0,0,n-1);
    while(q--)
    {
        cin>>temp>>l>>r;
        if(temp==4)
        {
            ans=query(0,0,n-1,l-1,r-1);
            chk(ans);
            cout<<ans<<endl;
        }
        else
        {
            cin>>v;
            if(temp==1)
                update1(0,0,n-1,l-1,r-1,v);
            else if(temp==2)
                update2(0,0,n-1,l-1,r-1,v);
            else
                update3(0,0,n-1,l-1,r-1,v);
        }
        //cout<<"after update or query"<<endl;
          /*cout<<temp<<" "<<l<<" "<<r<<" "<<v<<endl;
          f(i,0,n+4)
          cout<<i<<" "<<val[i]<<" "<<lazyadd[i]<<" "<<lazymul[i]<<" "<<flag[i]<<endl;
          cout<<endl;*/
    }
    return 0;
}
