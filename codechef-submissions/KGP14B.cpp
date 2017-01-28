#include<bits/stdc++.h>
int dp[1002][1002];
char s1[1002];
char s2[1002];
using namespace std;
int main() {
    int t, tc = 1;
    cin>>t;
    while(t--) {
        int p,q;
        scanf("%d%d",&p,&q);
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=p;i++) {
            for(int j=1;j<=q;j++) {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                if(s1[i]==s2[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
        printf("Case %d: %d\n",tc++, p+q-dp[p][q]);
    }
    return 0;
}
