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
	std::ios_base::sync_with_stdio(false);cin.tie(0);
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,k;
  char s[1009];
  scanf("%d%d",&n,&k);
  vector<int>one,zero;
  scanf("%s",s);
  for(int i=0;i<n;i++)
  {
   if(s[i] == 48)
    zero.push_back(i);
   else
    one.push_back(i);
  }
  int count=1,j;
  for(int i=0,j=0;count <= n-k;count++)
  {
   if(count&1){
    if(i<one.size())
     s[one[i++]] = 50;
    else
     s[zero[j++]]=50;
   }
   else{
    if(j<zero.size())
     s[zero[j++]] = 50;
    else
     s[one[i++]]=50;
   }
  }
  for(int i=0;i<n;i++)
   if(s[i]!=50)
    printf("%c",s[i]);
  printf("\n");
 }
 return 0;
}