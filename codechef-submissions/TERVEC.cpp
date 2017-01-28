#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;scanf("%d",&t);while(t--)
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
bool is_prime(int n)
{
    if(n%2==0)
        return 0;
    for(int i=3;i<=int(sqrt(n));i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
int jacobi(int a,int b)
{
    int j=1;
    if(a<0)
    {
        a=-1*a;
        if(b%4==3)
            j=-1*j;
    }
    while(a!=0)
    {
        while(a%2==0)
        {
            a=a/2;
            if(b%8==5 or b%8==3)
                j=-1*j;
        }
        int temp=b;
        b=a;
        a=temp;
        if(a%4==3 and b%4==3)
            j=-1*j;
        a=a%b;
    }
    if(b==1)
        return j;
    return 0;
}
int main() 
{
    int N;
    TC()
    {
        scanf("%d",&N);
        if((N&(N-1))==0)
        {
            bool H[N][N];
            H[0][0]=1;
            for(int n=1;n<N;n+=n)
                f(i,0,n)
                    f(j,0,n)
                    {
                        H[i+n][j]   =  H[i][j];
                        H[i][j+n]   =  H[i][j];
                        H[i+n][j+n] = !H[i][j];
                    }
            printf("YES\n");
            f(i,0,N)
                f(j,0,N)
                    if(H[i][j])
                        printf("1 ");
                    else
                        printf("-1 ");
            printf("\n");
        }
        else if(N%4==0)
        {
            printf("YES\n");
            int ar[N][N];
            int p=N-1;
            f(i,0,N)
                f(j,0,N)
                    if(i==0  or i==j)
                        ar[i][j]=1;
                    else if(j==0)
                        ar[i][j]=-1;
                    else
                        ar[i][j]=jacobi(i-j,p);
            f(i,0,N)
            {
                f(j,0,N)
                    printf("%d ",ar[i][j]);
                printf("\n");
            }
        }
        /*if(N%4==0 and is_prime(N/2-1))
        {
            int p=N/2-1;
            printf("YES\n");
            int ar[p][p];
            f(i,0,p)
                f(j,0,p)
                    if(i==0 and j==0)
                        ar[i][j]=0;
                    else if(i==0 or j==0)
                        ar[i][j]=1;
                    else if(j==0)
                        ar[i][j]=-1;
                    else if(i==j)
                        ar[i][j]=0;
                    else
                        ar[i][j]=jacobi(i-j,p);
                    
            f(i,0,p)
            {
                f(j,0,p)
                    cout<<ar[i][j]<<" ";
                cout<<endl;
            }
            printf("\n");
        }*/
        else
            printf("NO\n");
    }
	return 0;
}
