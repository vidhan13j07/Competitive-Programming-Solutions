#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int n = s.size();
	int id = -1, id1 = -1;
	for(int i = 0;i < n;i++)
		if((s[i] - '0')%2 == 0) {
			if(s[i] < s[n - 1] && id == -1)
				id = i;
			else if(s[i] > s[n - 1]) 
				id1 = i;
		}
	if(id != -1)
		swap(s[n - 1],s[id]);
	else if(id1 != -1)
		swap(s[n - 1],s[id1]);
	else {
		cout<<"-1\n";
		return 0;
	}
	cout<<s<<endl;
	return 0;
}