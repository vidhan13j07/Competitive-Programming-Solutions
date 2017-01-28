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
using namespace std;
void FastIO(){ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
//TEMPLATE ENDS HERE
const int N=1e5+5;
vll v1(N,0),v2(N,0);
//vector < pair<int,int> > b,sell;
//vector < pair<char ,pair<int,int> > > t;
int main() 
{
    FastIO();
    int n,s,temp1,temp2;
    cin>>n>>s;
    //cout<<n<<" "<<s<<endl;
    char ch;
    f(i,0,n)
    {
        cin>>ch>>temp1>>temp2;
        //trace3(ch,temp1,temp2);
        if(ch=='B')
            v1[temp1]+=temp2;
        else
            v2[temp1]+=temp2;
        //trace2(v1[temp1],v2[temp1]);
    }
    int k1=0;
    //cout<<N;
    k1=0;
    vector< pi > v;
    for(int i=0;i<N;i++)
    {
        if(v2[i]>0)
        {
            v.eb(mk(i,v2[i]));
            k1++;
        }
        if(k1==s)
            break;
    }
    for(int i=sc(v)-1;i>=0;i--)
        cout<<"S "<<v[i].fi<<" "<<v[i].se<<endl;
    k1=0;
    for(int i=N-1;i>=0;i--)
    {
        if(v1[i]>0)
        {
            cout<<"B "<<i<<" "<<v1[i]<<endl;
            k1++;
        }
        if(k1==s)
            break;
    }
    return 0;
}