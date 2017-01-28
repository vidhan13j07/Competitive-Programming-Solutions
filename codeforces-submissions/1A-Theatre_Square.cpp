#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() 
{
    ll n,m,a,x,y;
    cin>>n>>m>>a;
    x=m/a;
    if(m%a)
        x++;
    y=n/a;
    if(n%a)
        y++;
    cout<<x*y<<endl;
    return 0;
}