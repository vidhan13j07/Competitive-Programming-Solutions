#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;


#define f first
#define s second
#define pb push_back
#define mp make_pair
#define SET(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define printl(x) printf("%lld\n",x)
#define print(x) printf("%d\n",x)
#define printLL(x) printf("%I64d\n",x)
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

int main() {
    int n,t,i;
    sc(n);sc(t);
    if(t==10) {
        if(n==1) {
            cout<<"-1\n";
            return 0;
        }
        cout<<"1";
        for(i=1;i<=n-1;i++)
            cout<<"0";
        cout<<endl;
    }
    else {
        for(i=1;i<=n;i++)
            cout<<t;
        cout<<endl;
    }

    return 0;
}
