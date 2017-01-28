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
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

class node
{
	public:
		int parent,left,right;
};
map<int,node> mp;
const int N = 1e5 + 5;
int ar[N];
set<int> st;
node init(int p)
{
    node k;
    k.parent = p;
    k.left = k.right = -1;
    return k;
}
void traverse(int x)
{
	set<int>::iterator it = st.upper_bound(x);
	if(it == st.end())
		it--;
	int start = *it, k;
    //trace2(start,x);
	while(true)
	{
        if(start > x)
            k = mp[start].left;
        else
            k = mp[start].right;
		if(k == -1)
			break;
		start = k;
	}
	node kk = init(start);
	if(start < x)
		mp[start].right = x;
	else
		mp[start].left = x;
	mp[x] = kk;
    st.insert(x);
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d",&ar[0]);
	node x = init(-1);
	mp[ar[0]] = x;
	f(i,1,n)
		scanf("%d",&ar[i]);
	st.insert(ar[0]);
	f(i,1,n)
		traverse(ar[i]);
	//f(i,0,n)
	//	trace5(i,ar[i],mp[ar[i]].parent,mp[ar[i]].left,mp[ar[i]].right);
	f(i,1,n)
		printf("%d ",mp[ar[i]].parent);
	printf("\n");
    return 0;
}