#include<bits/stdc++.h>
using namespace std;
int col0,col1;
bool is;
const int MAXN = 505;
vector<int> adj[MAXN];
int col[MAXN];
void DFS(int s) {
    for(auto it: adj[s]) {
        if(col[it]!=-1) {
            if(col[s]==col[it]) is=false;
        }
        else {
            if(col[s]==0) col[it]=1,col1++;
            else col[it]=0,col0++;
            DFS(it);
        }
    }
}
int main() {
    int t;
    cin>>t;
    int cc=0;
    while(t--) {
        int n;
        col0=0;
        col1=0;
        ++cc;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) col[i]=-1,adj[i].clear();
        for(int i=1;i<=n;i++) {
            int p;
            scanf("%d",&p);
            for(int j=1;j<=p;j++) {
                int x;
                scanf("%d",&x);
                adj[i].push_back(x);
            }
        }
        is=true;
        for(int i=1;i<=n;i++) {
            if(col[i]==-1) col[i]=0,col0++,DFS(i);
        }
        if(is) printf("Case %d: 1 %d %d\n",cc,min(col0,col1),max(col0,col1));
        else printf("Case %d: 0 0 0\n",cc);
    }
    return 0;
}
