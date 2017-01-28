#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int ar[N], x[N];
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d", ar + i);
	for(int i = 0;i < n;i++) x[i] = ar[i];
	sort(x, x + n);
	int i = 0, j = n - 1;
	while(i < n && ar[i] == x[i])
		i++;
	while(j >= 0 && x[j] == ar[j])
		j--;
	if(j <= i) {
		printf("yes\n1 1\n");
		return 0;
	}
	int temp = i, te = j;
	while(i < te && ar[i] == x[j]) {
		//cout<<i<<" "<<j<<" "<<ar[i]<<" "<<x[j]<<endl;
		i++;
		j--;
	}
	if(i < te)
		printf("no\n");
	else 
		printf("yes\n%d %d\n",temp + 1,te + 1);
	return 0;
}