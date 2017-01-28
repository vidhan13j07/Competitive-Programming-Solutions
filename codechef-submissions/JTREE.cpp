#include<bits/stdc++.h>
#define ll long long int
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;
const int N = 1e5 + 5;
int root[N], depth[N];
vector<int> v[N];
vector< pair<int,int> > st[N];
ll ans[N];
int main()
{
    int n, m, qq;
    for(int i = 0;i < N;i++)
        ans[i] = 1LL*N*N*N;
    scanf("%d %d",&n, &m);
    for(int i = 1;i < n;i++) {
        int a, b;
        scanf("%d %d",&a, &b);
        a--;
        b--;
        v[b].emplace_back(a);
    }
    while(m--) {
        int a, k, w;
        scanf("%d %d %d",&a, &k, &w);
        a--;
        st[a].push_back( {w, k} );
    }
    queue<int> q;
    q.push(0);
    ans[0] = 0;
    while(!q.empty()) {
        int k = q.front(), temp = root[k];
        q.pop();
        vector<int> path;
        while(temp > 0) {
            path.emplace_back(temp);
            temp = root[temp];
        }
        path.emplace_back(0);
        int sz = path.size(), i = 0;
        sort(st[k].begin(), st[k].end());
        for(auto it: st[k]) {
            if(it.second >= depth[k]) {
                ans[k] = min(ans[k], (1LL)*it.first);
                break;
            }
            while(i < sz and i < it.second) {
                ans[k] = min(ans[k], (1LL)*it.first + ans[path[i]]);
                i++;
            }
        }
        for(auto it: v[k]) {
            q.push(it);
            root[it] = k;
            depth[it] = depth[k] + 1;
        }
    }
    scanf("%d",&qq);
    while(qq--) {
        int a;
        scanf("%d",&a);
        a--;
        printf("%lld\n", ans[a]);
    }
    return 0;
}
