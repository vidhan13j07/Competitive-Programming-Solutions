#include <bits/stdc++.h>
using namespace std;

map<string,string> mp;
int main() {
	int n, m;
	scanf("%d %d",&n, &m);
	string a, b;
	for(int i = 0;i < m;i++) {
		cin>>a>>b;
		string c = (a.size() <= b.size())?a:b;
		mp[a] = c;
	}
	for(int i = 0;i < n;i++) {
		cin>>a;
		cout<<mp[a]<<" ";
	}
	cout<<endl;
	return 0;
}