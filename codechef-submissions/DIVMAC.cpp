#include<bits/stdc++.h>
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define mk make_pair
#define fi first
#define se second
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
const int N = 1e6 + 5;
const int M = 1e5 + 5;
int fac[N];
vi prime;
int ar[M], seg[4*M], ma[4*M];
bool godown[4*M];
void pre() {
    f(i,2,N) {
		if(!fac[i]) {
			fac[i]=i;
			prime.eb(i);
		}
		int j=0;
		while(j < sc(prime) and i*prime[j] < N)
		{
			fac[i*prime[j]] = prime[j];
			j++;
		}
	}
	fac[1] = 1;
}
void build(int node, int i, int j) {
    if(i > j)
        return ;
    if(i == j) {
        ma[node] = fac[ar[i]];
        seg[node] = ar[i];
        if(ma[node] == 1)
            godown[node] = 0;
        else
            godown[node] = 1;
        return;
    }
    int mid = (i + j)/2;
    build(2*node + 1, i, mid);
    build(2*node + 2, mid + 1, j);
    ma[node] = max(ma[2*node + 1], ma[2*node + 2]);
    godown[node] = godown[2*node + 1] | godown[2*node + 2];
}
void update(int node, int i, int j,int l, int r) {
    if(i > j or i > r or j < l or !godown[node])
        return;
    //trace5(node, i, j, l, r);
    if(i == j) {
        seg[node] /= ma[node];
        ma[node] = fac[seg[node]];
        if(ma[node] == 1)
            godown[node] = 0;
        return;
    }
    int mid = (i + j)/2;
    update(2*node + 1, i, mid, l, r);
    update(2*node + 2, mid + 1, j, l, r);
    ma[node] = max(ma[2*node + 1], ma[2*node + 2]);
    godown[node] = godown[2*node + 1] | godown[2*node + 2];
}
int query(int node, int i, int j, int l, int r) {
    if(i > j or i > r or j < l)
        return 1;
    if(i >= l and j <= r)
        return ma[node];
    int mid = (i + j)/2;
    return max(query(2*node + 1, i, mid, l, r), query(2*node + 2, mid + 1, j, l, r));
}
int main()
{
    pre();
    TC() {
        int n, m;
        scanf("%d %d",&n, &m);
        f(i,0,n)
            scanf("%d", ar+i);
        build(0, 0, n - 1);
        while(m--) {
            int tp, l, r;
            scanf("%d %d %d",&tp, &l, &r);
            l--;
            r--;
            if(!tp)
                update(0, 0, n - 1, l, r);
            else
                printf("%d ", query(0, 0, n - 1, l, r));
            /*f(i,0,13)
                trace4(i, ma[i], seg[i], godown[i]);
            cout<<endl;*/
        }
        printf("\n");
    }
    return 0;
}
