#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100001000;
const int INF=1e9;
const ull ppp=131;

bool isprime[maxn];
int prime[maxn];int cnt=0;

void gprime(int n)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        prime[++cnt]=i;

        for(int j=1;j<=cnt&&i*prime[j]<=n;j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;cin>>n>>q;
    gprime(n);
    for(int i=1;i<=q;i++)
    {
        int k;cin>>k;
        cout<<prime[k]<<"\n";
    }

}