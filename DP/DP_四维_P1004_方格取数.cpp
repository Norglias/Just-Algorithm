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

int n;
int num[15][15];
int dp[15][15][15][15];

signed main()
{
    IOS;CT;
    cin>>n;
    while(1)
    {
        int x,y,w;cin>>x>>y>>w;
        if(x==0&&y==0&&w==0)
        break;
        num[x][y]=w;
    }   
    int ans=-INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int p=1;p<=n;p++)
                {
                    dp[i][j][k][p]=max(max(dp[i-1][j][k-1][p],dp[i-1][j][k][p-1]),
                    max(dp[i][j-1][k-1][p],dp[i][j-1][k][p-1]))+num[i][j]+num[k][p];
                    if(i==k&&j==p)
                    dp[i][j][k][p]-=num[i][j];
                }
            }
        }
    }
    cout<<dp[n][n][n][n];
}