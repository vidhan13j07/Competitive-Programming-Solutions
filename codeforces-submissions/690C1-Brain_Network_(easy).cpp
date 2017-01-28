#include<bits/stdc++.h>
using namespace std;
int X[1001];
vector<int>graph[1001];
bool bfs(int curr , int prev)
{
    for (int i=0 ; i<graph[curr].size() ; i++)
    {
        if(graph[curr][i]!=prev)
        {
            if(X[graph[curr][i]]==1)
                return 0;
            else
            {
                X[graph[curr][i]]=1;
                bool dh=bfs(graph[curr][i],curr);
                if(dh==0)
                    return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int N,M;
    cin>>N>>M;
    for (int i=0 ; i<M ; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool ch;
    X[1]=1;
    ch=bfs(1,-1);
    if(ch==0)
    {
        cout<<"no\n";
        return 0;
    }
    for (int i=1 ; i<=N ; i++)
    {
        if(X[i]==0)
        {
            //cout<<i<<endl;
            cout<<"no\n";
            return 0;
        }
    }
    cout<<"yes\n";
}
