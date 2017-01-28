#include <bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N=200005;
int ar[N],lef[N],righ[N];
int main()
{
   int n,k,x;
   cin>>n>>k>>x;
   f(i,0,n)
       cin>>ar[i];
   lef[0]=0;
   f(i,1,n)
       lef[i]=lef[i-1] | ar[i-1];
   righ[n-1]=ar[n-1];
   for(int i=n-2;i>=0;i--)
       righ[i]=righ[i+1] | ar[i];
   /*f(i,0,n)
       cout<<lef[i]<<" ";
   cout<<endl;
   f(i,0,n)
       cout<<righ[i]<<" ";
   cout<<endl;*/
   ll temp=1,ma=0;
   f(i,0,k)
        temp*=x;
   f(i,0,n)
       ma=max(ma,((temp*ar[i]) | (lef[i] | righ[i+1])));
   cout<<ma<<endl;
   return 0;
}