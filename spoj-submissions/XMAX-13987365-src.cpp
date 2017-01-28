#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

#define ull unsigned long long
#define testcases() int var;  cin>>var; while(var--)

int length(ull n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n>>=1;
    }
    return cnt;
}

int main()
{   
    int n;
    cin>>n;
    ull a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
	int lengths[n]; 
    for(int i=0; i<n; i++)
       lengths[i] = length(a[i]);
    vector<ull> buckets[65];
    for(int i=0; i<n; i++)
        buckets[lengths[i]].push_back(a[i]);
	ull modified_array[100], m_index = 0;
	for(int i=64; i>0; i--) 
        {
            if(buckets[i].size()) 
            {
                
                modified_array[m_index++]=buckets[i][0];

                
                for(int j=1; j<buckets[i].size(); j++)
                {
                    ull temp = buckets[i][0] ^ buckets[i][j];
                    int len = length(temp);
                    buckets[len].push_back(temp);
                }
            }
        }

        
        ull ans = 0;
        for(int i=0; i<m_index; i++) 
            if(ans < (ans ^ modified_array[i]))
                ans = (ans ^ modified_array[i]);

        
        cout<<ans<<endl;
    return 0;
}