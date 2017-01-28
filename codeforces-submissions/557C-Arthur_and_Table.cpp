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
#define endl "\n"
#define fi first
#define se second 
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
pair<int,int> v[100005];
bool cmp(pair<int,int> i,pair<int,int> j)
{
    if(i.fi!=j.fi)
        return (i.fi>j.fi);
    else
        return (i.se<=j.se);
}
int ar[201];
int main() 
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int l[n],d[n];
    memset(ar,0,sizeof(ar));
    f(i,0,n)
        cin>>l[i];
    f(i,0,n)
    {
        cin>>d[i];
        v[i]=mk(l[i],d[i]);
        ar[d[i]]++;
    }
    sort(v,v+n,cmp);
    /*f(i,0,n)
        cout<<v[i].fi<<" "<<v[i].se<<endl;
    cout<<"start"<<endl;*/
    int i,j,k,c;
    ll s=0,temp,ans=1e10,temp1;
    int si=n;
    i=0,j=0;
    while(i<si)
    {
        temp=0,k=0,temp1=s;
        while(j<si and v[i].fi==v[j].fi)
        {
            k++;
            ar[v[j].se]--;
            temp+=v[j].se;
            j++;
        }
        //cout<<i<<" "<<j<<" "<<k<<" "<<temp<<endl;
        /*f(a,1,201)
            if(ar[a])
                cout<<a<<" ";
        cout<<endl;*/
        c=n;
        f(a,1,201)
        {
            if(2*k>c)
                break;
            if(2*k+ar[a]>c)
                while(ar[a] and 2*k<=c)
                {
                    c--;
                    temp1+=a;
                }
            else
            {
                c-=ar[a];
                temp1+=(a*ar[a]);
            }
        }
        //cout<<temp1<<endl;
        n-=k;
        i=j;
        ans=min(ans,temp1);
        s+=temp;
    }
    cout<<ans<<endl;
    return 0;
}