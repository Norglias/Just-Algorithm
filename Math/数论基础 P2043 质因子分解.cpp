#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e18+10;

int prime[10010];

void findp(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                n/=i;
                count++;
            }
            prime[i]+=count;
        }
    }
    if(n>1)
    prime[n]++;
}


signed main()
{
    int n;cin>>n;
    for(int i=2;i<=n;i++)
    findp(i);

    for(int i=1;i<=n;i++)
    {
        if(prime[i]==0)
        continue;

        cout<<i<<" "<<prime[i]<<"\n";
    }
}