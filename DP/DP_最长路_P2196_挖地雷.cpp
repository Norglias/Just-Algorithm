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
const int mod=1e9+7;
const int ppp=131;

int n,w;
int num[25];
int qwq[25][25];
int dp[25];
int pre[25];

void solve(int x)
{
    if(pre[x])
    solve(pre[x]);

    cout<<x<<" ";
}

signed main()
{
    IOS;CT;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
        cin>>qwq[i][j];

    int maxx=-INF,enode=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=num[i];
        for(int j=1;j<i;j++)
        {
            if(qwq[j][i]&&dp[i]<dp[j]+num[i])
            {
                dp[i]=dp[j]+num[i];
                pre[i]=j;
            }
        }
        if(dp[i]>maxx)
        {
            maxx=dp[i];
            enode=i;
        }
    }
    solve(enode);
    cout<<"\n";
    cout<<maxx;
}