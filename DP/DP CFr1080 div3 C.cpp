#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int t;
int num[maxn];
int dp[maxn][10];
signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;cin>>n;
        for(int j=1;j<=n;j++)
        cin>>num[j];
        
        for(int j=1;j<=6;j++)
        {
            if(j==num[1])
            dp[1][j]=0;
            else
            dp[1][j]=1;
        }
        for(int j=2;j<=n;j++)
        {
            int cur=num[j];
            
            for(int k=1;k<=6;k++)
            {
                int c=1;
                if(num[j]==k)
                c=0;
                dp[j][k]=INF;
                for(int p=1;p<=6;p++)
                {
                    if(k!=p&&k+p!=7)
                    dp[j][k]=min(dp[j][k],dp[j-1][p]+c);
                }
            }
        }
        int ans=INF;
        for(int j=1;j<=6;j++)
        ans=min(ans,dp[n][j]);

        cout<<ans<<"\n";
    }
}