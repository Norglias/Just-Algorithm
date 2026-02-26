#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e18+10;

bool notprime[50050];
int prime[maxn],cnt;

bool range[maxn];

void p(int n)
{
    notprime[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!notprime[i])
        {
            prime[++cnt]=i;
        }

        for(int j=1;j<=cnt&&i*prime[j]<=n;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            break;
        }
    }
}

signed main()
{
    int l,r,ans=0;cin>>l>>r;
    
    memset(range,1,sizeof(range));
    if(l==1)
    range[0]=0;
    p(50000);
    for(int i=1;i<=cnt;i++)
    {
        int pcur=prime[i];
        if(pcur*pcur>r)
        break;

        int lll=(l+pcur-1)/pcur*pcur;

        if(lll==pcur)
        lll=2*pcur;

        for(int i=lll;i<=r;i+=pcur)
        range[i-l]=0;
    }

    for(int i=0;i<=r-l;i++)
    {
        if(range[i])
        ans++;
    }
    cout<<ans;
}