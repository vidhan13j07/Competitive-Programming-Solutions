#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define sc(v) v.size()
#define eb emplace_back
#define pb pop_back
#define stl(a,it) for(auto it: a)
#define what_is(x) cerr << #x << " is " << x << endl
#define f(i,a,b) for(int i=a;i<b;i++)
#define contain(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define mk make_pair
template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
    bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        Pred p;
        return p(left.second, right.second);
    }
};
using namespace std;
int main() 
{
	//std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,n1,n2,c,k,i;
	cin>>t;
	string key,msg;
	vector <char> v;
	int temp;
	while(t--)
	{
		cin>>key>>msg;
		v.clear();
		n1=sc(key);
		n2=sc(msg);
		i=0;
		c=0;
		k=0;
		while(i<n2)
		{
			temp=(int)msg[i]-(int)key[k]+'0';
			//cout<<msg[i]<<" "<<key[k]<<" "<<temp<<endl;
			if(temp<'a')
				temp+=26;
			v.eb(temp);
			if(c&1)
				k--;
			else
				k++;
			if(k==-1)
			{
				c++;
				k=0;
			}
			else if(k==n1)
			{
				c++;
				k=n1-1;
			}
			i++;
		}
		//cout<<msg<<endl;
		f(i,0,sc(v))
			cout<<v[i];
		cout<<endl;
	}
	return 0;
}
/*
mumtaaz
shrishtika
leadingzerosareimportant
iloveyou
keadimfzerorzreimonrtans
abhimanyu
*/