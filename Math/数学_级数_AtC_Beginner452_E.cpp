#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=998244353;
const int ppp=131;

int n,m;
int a[maxn],b[maxn];
int sum[maxn];

signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=m;i++)
    cin>>b[i];
    
    int ans=0;
    for(int i=1;i<=n;i++)
    ans=(ans+(i*a[i])%mod)%mod;
    
    int sss=0;
    for(int i=1;i<=m;i++)
    sss=(sss+b[i]%mod)%mod;
    ans=(ans*(sss%mod))%mod;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n/i;j++)
        {
            int r=min(n,(j+1)*i-1);
            int cur=sum[r]-sum[i*j-1];
            cur=(cur%mod+mod)%mod;
            int popo=(i*j*(cur%mod))%mod;
            int ada=((popo%mod)*(b[i]%mod))%mod;
            ans=(ans-ada)%mod;
        }
    }
    cout<<(ans+mod)%mod;
}