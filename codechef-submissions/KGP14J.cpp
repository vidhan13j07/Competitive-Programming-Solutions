#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1;tc <= t;tc++) {
        int x, y;
        scanf("%d %d",&x, &y);
        int len = 0, tmp = y;
        while(tmp) {
            len++;
            tmp /= 10;
        }
        for(int i = 1;;i++) {
            long double d = i*log10(x);
            int k = (int)(powl(10.0L, len - 1 + d - floor(d)));
            if(k == y) {
                printf("Case %d: %d\n", tc, i);
                break;
            }
        }
    }
    return 0;
}
