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
int main()
{
	int activities;
	string origin, activity;
	string all[4] = {"CONTEST_WON", "TOP_CONTRIBUTOR", "BUG_FOUND", "CONTEST_HOSTED"};
	TC() {
		scanf("%d",&activities);
		cin>>origin;
		int laddus = 0, x, ind;
		while(activities--)
		{
			cin>>activity;
			f(i,0,4)
				if(activity == all[i])
				{
					if(i == 0 || i == 2)
						scanf("%d",&x);
					ind = i;
				}
			if(ind == 0)
				laddus += 300 + max(0, 20 - x);
			else if(ind == 1)
				laddus += 300;
			else if(ind == 2)
				laddus += x;
			else
				laddus += 50;
		}
		if(origin == "INDIAN")
			printf("%d\n",laddus / 200);
		else
			printf("%d\n",laddus / 400);
	}
    return 0;
}
