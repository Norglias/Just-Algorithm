#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
const ll INF1=1e19+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;

int n,lpos,rpos;

int dp[maxn];
int num[maxn];
int qu[maxn];


signed main()
{
    IOS;CT;
    cin>>n>>lpos>>rpos;
    for(int i=0;i<=n;i++)
    {
        cin>>num[i];
        dp[i]=-INF;
    }
    dp[0]=num[0];
    int h=1,t=0;
    for(int i=lpos;i<=n;i++)
    {
        int r=i-lpos;
        while(h<=t&&dp[r]>=dp[qu[t]])
        t--;
        qu[++t]=r;
        while(h<=t&&qu[h]<i-rpos)
        h++;
        dp[i]=dp[qu[h]]+num[i];
    }
    int ans=-INF;
    for(int i=max(0LL,n-rpos+1);i<=n;i++)
    ans=max(ans,dp[i]);
    cout<<ans;
}