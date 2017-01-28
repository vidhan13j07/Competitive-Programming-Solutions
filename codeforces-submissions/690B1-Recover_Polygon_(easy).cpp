#include<bits/stdc++.h>
using namespace std;
int X[51][51],Y[51][51];
int main()
{
    int N;
    cin>>N;
    int cnt=0,ch=0,x,y;
    for (int i=0 ; i<N ; i++)
    {
        string S;
        cin>>S;
        for (int j=0 ; j<S.size() ; j++)
        {
            X[i][j]=S[j]-'0';
            if (X[i][j]==4)
            {
                if(ch==0)
                    x=i,y=j;
                ch=1;
                cnt++;
            }
        }
    }
    if(cnt==0)
    {
        cout<<"No\n";
        return 0;
    }
    int u=x,v=y;
    while (X[u][v]==4 && v<N)
    {
        Y[u][v]=1;
        v++;
        cnt--;
    }
    u++;
    while(cnt!=0 && X[u][y]==4 && u<N)
    {
        for (int j=y ; j<v ; j++)
        {
            Y[u][j]=1;
            if(X[u][j]!=4 || cnt==0)
            {
                cout<<"No\n";
                return 0;
            }
            else
                cnt--;
        }
        u++;
    }
    if(cnt!=0)
    {
        cout<<"No\n";
        return 0;
    }
    //cout<<x<<" "<<u<<" "<<y<<" "<<v<<endl;
    x--;
    y--;
    if(x!=-1 && y!=-1)
    {
        Y[x][y]=1;
        if(X[x][y]!=1)
        {
            cout<<"No\n";
            return 0;
        }
    }
    if(x!=-1 && v!=N)
    {
        Y[x][v]=1;
        if(X[x][v]!=1)
        {
            cout<<"No\n";
            return 0;
        }
    }
    if(u!=N && y!=-1)
    {
        Y[u][y]=1;
        if(X[u][y]!=1)
        {
            cout<<"No\n";
            return 0;
        }
    }
    if(u!=N && v!=N)
    {
        Y[u][v]=1;
        if(X[u][v]!=1)
        {
            cout<<"No\n";
            return 0;
        }
    }
    //cout<<"Heya\n";
    if(x!=-1)
    {
        for (int i=y+1 ; i<v ; i++)
        {
            Y[x][i]=1;
            if(X[x][i]!=2)
            {
                cout<<"No\n";
                return 0;
            }
        }
    }
    if(u!=N)
    {
        for (int i=y+1 ; i<v ; i++)
        {
            Y[u][i]=1;
            if(X[u][i]!=2)
            {
                cout<<"No\n";
                return 0;
            }
        }
    }
    if(y!=-1)
    {
        for (int i=x+1 ; i<u ; i++)
        {
            Y[i][y]=1;
            //cout<<i<<" "<<y<<endl;
            if(X[i][y]!=2)
            {
                cout<<"No\n";
                return 0;
            }
        }
    }
    if(v!=N)
    {
        for (int i=x+1 ; i<u ; i++)
        {
            Y[i][v]=1;
            if(X[i][v]!=2)
            {
                cout<<"No\n";
                return 0;
            }
        }
    }
    //cout<<"Bhola re Bhola \n";
    for (int i=0 ; i<N; i++)
    {
        for (int j=0 ; j<N; j++)
        {
            if(Y[i][j]==0 && X[i][j]!=0)
            {
                //cout<<i<<" "<<j<<" "<<Y[i][j]<<endl;
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";

}
