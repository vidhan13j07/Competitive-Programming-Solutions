#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 5;
ll ar[N], cnt[N];
pair< pair<int,int>,int> p[N];
ll tree[N + N];
ll read(int i) {
	ll sum = 0;
	while(i > 0) {
		sum += tree[i];
		i -= (i & (-i));
	}
	return sum;
}
void update(int i, ll val) {
	//cout<<i<<" "<<val<<endl;
	while(i < N) {
		tree[i] += val;
		i += (i & (-i));
	}
}
int main() {
	int n, m, k;
	scanf("%d %d %d",&n, &m, &k);
	for(int i = 0;i < n;i++) scanf("%lld",&ar[i]);
	for(int i = 0;i < m;i++) scanf("%d %d %d",&p[i].first.first, &p[i].first.second, &p[i].second);
	for(int i = 0;i < N;i++) cnt[i] = 0;
	for(int i = 0;i < k;i++) {
		int l, r;
		scanf("%d %d",&l, &r);
		cnt[l - 1]++;
		cnt[r]--;
	}
	for(int i = 1;i < N;i++) cnt[i] += cnt[i - 1];
	for(int i = 0;i < m;i++) {
		//cout<<i<<" "<<cnt[i]<<" "<<p[i].first.first<<" "<<p[i].first.second<<" "<<p[i].second<<endl;
		ll val = cnt[i] * p[i].second;
		update(p[i].first.first,val);
		update(p[i].first.second + 1, -1*val);
	}
	for(int i = 0;i < n;i++) ar[i] += read(i + 1);
	for(int i = 0;i < n;i++) printf("%lld ",ar[i]);
	printf("\n");
	return 0;
}