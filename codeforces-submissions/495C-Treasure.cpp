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
int main() 
{
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string st;
    cin>>st;
    int c=0,id,k;
    vector <int> v;
    bool flag=1;
    f(i,0,sc(st))
    {
        if(st[i]=='(')
            c++;
        else if(st[i]==')')
            c--;
        else
        {
            v.eb(1);
            c--;
            id=i;
        }
        if(c<0)
            flag=0;
    }
    if(sc(v)>0)
        v[sc(v)-1]+=c;
    else
        flag=0;
    c=0,k=0;
    f(i,0,sc(st))
    {
        if(st[i]=='(')
            c++;
        else if(st[i]==')')
            c--;
        else
            c-=v[k++];
        if(c<0)
            flag=0;
        //cout<<c<<endl;
    }
    if(c!=0)
        flag=0;
    if(not flag)
        cout<<"-1"<<endl;
    else
    {
        f(i,0,sc(v))
            cout<<v[i]<<endl;
    }
    return 0;
}