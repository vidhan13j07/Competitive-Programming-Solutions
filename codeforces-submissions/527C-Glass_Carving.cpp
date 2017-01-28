#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, h, n, xx;
	char ch;
	scanf("%d %d %d",&w, &h, &n);
	multiset<int> a, b, x, y;
	a.clear();b.clear();x.clear();y.clear();
	a.insert(0);
	b.insert(0);
	x.insert(w);
	y.insert(h);
	while(n--) {
		cin>>ch>>xx;
		//scanf("%c %d",&ch, &xx);
		//cout<<ch<<" "<<xx<<endl;
		if(ch == 'V') {
			multiset<int>::iterator it = a.upper_bound(xx);
			int low, high;
			if(it == a.end())
				high = w;
			else
				high = *it;
			if(it == a.begin())
				low = 1;
			else
				low = *(--it);
			a.insert(xx);
			int diff = high - low;
			//cout<<"A "<<low<<" "<<high<<" "<<diff<<" "<<xx - low<<" "<<high - xx<<endl;
			x.erase(x.find(diff));
			x.insert(xx - low);
			x.insert(high - xx);
		}
		else {
			multiset<int>::iterator it = b.upper_bound(xx);
			int low, high;
			if(it == b.end())
				high = h;
			else
				high = *it;
			if(it == b.begin())
				low = 1;
			else
				low = *(--it);
			b.insert(xx);
			int diff = high - low;
			//cout<<"B "<<low<<" "<<high<<" "<<diff<<" "<<xx - low<<" "<<high - xx<<endl;
			y.erase(y.find(diff));
			y.insert(xx - low);
			y.insert(high - xx);
		}
		long long int h1 = (1LL) * (*x.rbegin());
		long long int h2 = (1LL) * (*y.rbegin());
		//cout<<h1<<" "<<h2<<endl;
		printf("%lld\n",h1 * h2);
	}
	return 0;
}