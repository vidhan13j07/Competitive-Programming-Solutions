#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
	int n, m;
	scanf("%d %d",&n, &m);
	for(int i = 0;i < m;i++) scanf("%d", a + i);
	long long int ans = 0;
	int x = 1;
	for(int i = 0;i < m;i++) {
		//cout<<i<<" "<<x<<" "<<a[i]<<" "<<ans<<endl;
		if(x > a[i]) {
			ans += n - x + 1;
			x = 1;
		}
		ans += a[i] - x;
		x = a[i];
	}
	printf("%lld\n", ans);
	return 0;
}