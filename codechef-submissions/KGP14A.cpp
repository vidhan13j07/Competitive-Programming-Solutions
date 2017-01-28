#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N], b[N];
int main() {
    int n, t, tc = 1;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d", a+i);
        for(int i = 0;i < n;i++)
            scanf("%d", b+i);
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        for(int i = 0;i < n;i++)
            ans += abs(a[i] - b[i]);
        printf("Case %d: %d\n", tc++, ans);
    }
    return 0;
}
