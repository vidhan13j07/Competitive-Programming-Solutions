#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>graph[10001];
ll Ans=0;
int main()
{
    int N;
    cin>>N;
    for(int i=1 ; i<N ; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1 ; i<=N ; i++)
    {
        ll b=graph[i].size();
        Ans=Ans+(b*(b-1))/2;
    }
    cout<<Ans<<endl;
}
