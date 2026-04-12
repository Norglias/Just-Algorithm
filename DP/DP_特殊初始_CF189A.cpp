#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;

int n,a,b,c;
int dp[maxn];
int num[5];

signed main()
{
    IOS;CT;
    cin>>n>>num[1]>>num[2]>>num[3];
    for(int i=1;i<=n;i++)
    dp[i]=-INF;
    dp[0]=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<=n;j++)
        if(j>=num[i])
        {
            dp[j]=max(dp[j],dp[j-num[i]]+1);
        }
    }
    cout<<dp[n];   
}