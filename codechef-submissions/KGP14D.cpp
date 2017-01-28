#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> ar[102];
int cnt;
pair<int,int> aux[102];
int dp[102][100003];
int go(int idx, int t) {
    if(idx==cnt+1) return 0;
    if(dp[idx][t]!=-1) return dp[idx][t];
    int ret;
    ret=go(idx+1,t)+1;
        if(t+aux[idx].second+30<=aux[idx].first) ret=min(ret,go(idx+1,t+aux[idx].second));
    return dp[idx][t]=ret;
}
bool cmp(const pair<int,int> &A, const pair<int,int> &B) {
    if(A.first==B.first) return A.second<B.second;
    return A.first<B.first;
}
int main() {
    int t;
    cin>>t;
    int cc=0;
    while(t--) {
        ++cc;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&ar[i].first);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ar[i].second);
        }
        cnt=1;
        for(int i=1;i<=n;i++) {
            if(ar[i].second!=-1) aux[cnt++]=make_pair(ar[i].second,ar[i].first);
        }
        cnt--;
        sort(aux+1,aux+1+cnt,cmp);
        printf("Case %d: %d\n",cc,go(1,0));
    }
}
