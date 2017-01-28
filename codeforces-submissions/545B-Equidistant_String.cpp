#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
const int l=100005;
using namespace std;
int main()
{
    char st[l],st1[l],st2[l];
    for(int i=0;i<l;i++)
    {
        st[i]='\0';
        st1[i]='\0';
        st2[i]='\0';
    }
    cin>>st>>st1;
    int t1,n,k;
    n=strlen(st);
    for(int i=0;i<n;i++)
        if(st[i]!=st1[i])
            t1++;
    k=0;
    if(t1%2==0)
    {
        for(int i=0;i<n;i++)
        {
            if(st[i]==st1[i])
                st2[i]=st1[i];
            else
            {
                if(k%2==0)
                    st2[i]=st[i];
                else
                    st2[i]=st1[i];
                k++;
            }
        }
        //cout<<st<<"\n"<<st1<<endl;
        cout<<st2<<endl;
    }
    else
        cout<<"impossible"<<endl;
    return 0;
}