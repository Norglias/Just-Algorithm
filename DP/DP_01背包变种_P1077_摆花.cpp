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
const int mod=1e6+7;
const int ppp=131;

int n,m;
int num[maxn];
int dp[1000];

signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=1;k<=min(j,num[i]);k++)
            {
                dp[j]=(dp[j]+dp[j-k])%mod;
            }
        }
    }
    cout<<dp[m];
    
}