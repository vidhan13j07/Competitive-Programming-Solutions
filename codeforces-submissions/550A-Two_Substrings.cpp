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
    string str;
    cin >> str;
    int ab = str.find("AB");
    int ba = str.rfind("BA");
    if(ab==string::npos || ba==string::npos)
        printf("NO\n");
    else 
    {
        if(ab-ba<2 && ba-ab<2) 
        {
            ab = str.rfind("AB");
            ba = str.find("BA");
            if(ab-ba<2 && ba-ab<2)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}