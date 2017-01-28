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
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
int main() 
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x0,y0,x1,y1,temp,k,temp1,temp2,temp3;
    deque < pair<int,int> > v;
    cin>>n>>x0>>y0;
    f(i,0,n)
    {
        cin>>x1>>y1;
        v.eb(mk(x1,y1));
    }
    int ar[n]={0};
    k=0;
    //cout<<x0<<" "<<y0<<endl;
    //f(i,0,sc(v))
    //  cout<<v[i].first<<" "<<v[i].second<<endl;
    f(i,0,n)
    {
        if(!ar[i])
        {
            f(j,i+1,n)
                if(!ar[j])
                {
                    temp1=x0*(v[i].second-v[j].second);
                    temp2=v[i].first*(v[j].second-y0);
                    temp3=v[j].first*(y0-v[i].second);
                    //cout<<i<<" "<<j<<" "<<temp1<<" "<<temp2<<" "<<temp3<<endl;
                    temp=temp1+temp2+temp3;
                    if(temp==0)
                        ar[j]=1;
                    //cout<<i<<" "<<j<<" "<<temp<<endl;
                }
            k++;
            //cout<<i<<endl;
        }
    }
    cout<<k<<endl;
    return 0;
}