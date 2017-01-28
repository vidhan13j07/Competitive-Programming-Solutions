#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int ar[N];
int main() {
	int n, l;
	scanf("%d %d",&n, &l);
	for(int i = 0;i < n;i++) scanf("%d",&ar[i]);
	sort(ar,ar + n);
	int diff = 2*ar[0];
	for(int i = 1;i < n;i++) diff = max(diff, ar[i] - ar[i - 1]);
	diff = max(diff, (2 * (l - ar[n - 1])));
	double ans = diff / 2.0;
	printf("%lf\n",ans);
	return 0;
}