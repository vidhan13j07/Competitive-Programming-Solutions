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
const int N=1e5+5;
pi p[N];
int vis[N];
int main() 
{
    int n,minx,miny,maxx,maxy,fmix,smix;
    TC()
    {
        scanf("%d",&n);
        f(i,0,n)
        {
            scanf("%d %d",&p[i].fi,&p[i].se);
            vis[i]=0;
            if(i==0)
            {
                minx=p[i].fi;miny=p[i].se;maxx=p[i].fi;maxy=p[i].se;
            }
            else
            {
                if(maxx<p[i].fi)
                    maxx=p[i].fi;
                if(maxy<p[i].se)
                    maxy=p[i].se;
                if(minx>p[i].fi)
                    minx=p[i].fi;
                if(miny>p[i].se)
                    miny=p[i].se;
            }
        }
        bool fl=0;
        if(p[0].fi<p[1].fi)
        {
            fmix=0;
            smix=1;
        }
        else
        {
            fmix=1;
            smix=0;
        }
        f(i,0,n)
        {
            if(p[i].fi==maxx and p[i].se==maxy)
            {
                printf("1\n%d SW\n",i+1);
                fl=1;
                break;
            }
            else if(p[i].fi==minx and p[i].se==maxy)
            {
                printf("1\n%d SE\n",i+1);
                fl=1;
                break;
            }
            else if(p[i].fi==minx and p[i].se==miny)
            {
                printf("1\n%d NE\n",i+1);
                fl=1;
                break;
            }
            else if(p[i].fi==maxx and p[i].se==miny)
            {
                printf("1\n%d NW\n",i+1);
                fl=1;
                break;
            }
            if(i>1)
            {
                if(p[i].fi<p[fmix].fi)
                {
                    smix=fmix;
                    fmix=i;
                }
                else if(p[i].fi<p[smix].fi)
                    smix=i;
            }
        }
        if(fl)
            continue;
        printf("2\n");
        if(p[smix].se>p[fmix].se)
            printf("%d SE\n%d NE\n",(smix+1),(fmix+1));
        else
            printf("%d SE\n%d NE\n",(fmix+1),(smix+1));
    }
    return 0;
}
