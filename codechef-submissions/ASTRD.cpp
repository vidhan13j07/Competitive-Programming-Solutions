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
        pair < double , pair < double , double > > p[155];
        int n,c[8];
        bool vis[8];
        inline double fRand(double fMax)
        {
            double f = (double)rand() / RAND_MAX;
            return f*fMax;
        }
        int cal(double c[3])
        {
        	double x[3],constant,temp,con;
        	int mi=155;
        	f(k,0,8)
        	{
        		f(j,0,3)
        			if(k&(1<<j))
        				x[j]=c[j]*-1.0;
        			else
        				x[j]=c[j];
        		constant=x[0]*x[0]+x[1]*x[1]+x[2]*x[2];
        		con=sqrt(constant)*0.001;
        		int cnt=0;
        		f(i,0,n)
        		{
        			temp=x[0]*p[i].fi+x[1]*p[i].se.fi+x[2]*p[i].se.se-constant;
        			if(temp>0.0 and fabs(temp)>=con)
        				cnt++;
        		}
        		mi=min(mi,cnt);
        	}
        	return mi;
        }
        inline int cal_min(double x[3])
        {
        	int mi=150;
        	mi=min(mi,cal(x));
        	swap(x[1],x[2]);
       		mi=min(mi,cal(x));
       		swap(x[0],x[1]);
        	mi=min(mi,cal(x));
       		swap(x[1],x[2]);
        	mi=min(mi,cal(x));
       		swap(x[1],x[0]);
        	mi=min(mi,cal(x));
        	swap(x[1],x[2]);
        	mi=min(mi,cal(x));
        	return mi;
        }
        int main() 
        {
        	int mi,r;
        	double x[3];
        	TC()
        	{
        		scanf("%d %d",&n,&r);
        		f(i,0,n)
        			scanf("%lf %lf %lf",&p[i].fi,&p[i].se.fi,&p[i].se.se);
        		x[0]=r;
        		x[1]=x[2]=0;
        		mi=cal_min(x);
        		int N=2e3+1e2+8e1;
        		f(i,0,N)
        		{
        			if(mi==0.0)
        				break;
        			x[0]=fRand(r);
        			x[1]=fRand(r);
        			if(x[0]*x[0]+x[1]*x[1]>=1.0*r*r)
        				continue;
        			x[2]=sqrt(1.0*r*r-x[0]*x[0]-x[1]*x[1]);
        			//trace3(x[0],x[1],x[2]);
        			mi=min(mi,cal_min(x));
        			//c++;
        		}
        		/*f(i,0,n)
        		{
        			double temp=sqrt(p[i].fi*p[i].fi+p[i].se.fi*p[i].se.fi+p[i].se.se*p[i].se.se);
        			temp=(1.0*r)/temp;
        			x[0]=p[i].fi*temp;
        			x[1]=p[i].se.fi*temp;
        			x[2]=p[i].se.se*temp;
        			mi=min(mi,cal_min(x));
        		}*/
        		//cout<<c<<endl;
        		printf("%d\n",mi);
        	}
        	return 0;
        }
