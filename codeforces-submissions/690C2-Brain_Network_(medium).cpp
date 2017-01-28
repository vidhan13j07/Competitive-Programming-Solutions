#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int Y[100001],X[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int>DFS;
    int large=1,point=1;
    DFS.push_back(1);
    X[1]=1;
    while(!(DFS.empty()))
    {
        int a=DFS[DFS.size()-1];
        //cout<<a<<endl;
        if(DFS.size()>large)
        {
            large=DFS.size();
            point=a;
        }
        int b=graph[a].size();
        if(b!=Y[a])
        {
            //cout<<graph[a][b-Y[a]-1]<<endl;
            if(X[graph[a][b-Y[a]-1]]==0)
            {
                DFS.push_back(graph[a][b-Y[a]-1]);
                X[graph[a][b-Y[a]-1]]=1;
            }
            Y[a]++;
        }
        else
            DFS.pop_back();
    }
    memset(X,0,sizeof(X));
    memset(Y,0,sizeof(Y));
    DFS.push_back(point);
    X[point]=1;
    while (!(DFS.empty()))
    {
        int a=DFS[DFS.size()-1];
        //cout<<a<<endl;
        if(DFS.size()>large)
        {
            large=DFS.size();
            point=a;
        }
        int b=graph[a].size();
        if(b!=Y[a])
        {
            if(X[graph[a][b-Y[a]-1]]==0)
            {
                DFS.push_back(graph[a][b-Y[a]-1]);
                X[graph[a][b-Y[a]-1]]=1;
            }
            Y[a]++;
        }
        else
            DFS.pop_back();
    }
    cout<<large-1<<endl;
}
