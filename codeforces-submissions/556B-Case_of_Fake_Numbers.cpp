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
    int n,k;
    cin>>n;
    int ar[n];
    f(i,0,n)
        cin>>ar[i];
    k=ar[0];
    bool flag=1;
    if(k<n-k)
    {
        f(i,1,n)
        {
            if(i&1)
                ar[i]=(ar[i]+k)%n;
            else    
            {
                ar[i]-=k;
                while(ar[i]<0)
                    ar[i]+=n;
            }
            if(ar[i]!=i)
                flag=0;
            //cout<<ar[i]<<" ";
        }
        //cout<<endl;
    }
    else
    {
        //cout<<"second"<<endl;
        k=n-k;
        f(i,1,n)
        {
            if(i%2==0)
                ar[i]=(ar[i]+k)%n;
            else    
            {
                ar[i]-=k;
                while(ar[i]<0)
                    ar[i]+=n;
            }
            if(ar[i]!=i)
                flag=0;
            //cout<<ar[i]<<" ";
        }
        //cout<<endl;
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}