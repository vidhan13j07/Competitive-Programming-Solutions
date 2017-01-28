#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int main() {
	int n, m, k, ans = 0;
	scanf("%d %d %d",&n, &m, &k);
	for(int i = 0;i <= m;i++) scanf("%d", a + i);
	for(int i = 0;i < m;i++) {
		int x = a[i] ^ a[m];
		int kk = 0;
		while(x) {
			if(x & 1)
				kk++;
			x >>= 1;
		}
		if(kk <= k)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}