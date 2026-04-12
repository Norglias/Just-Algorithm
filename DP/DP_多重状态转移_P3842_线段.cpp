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
int l[maxn],r[maxn];
int dp[20010][10];


signed main()
{
    IOS;CT;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    dp[1][0]=r[1]-1+r[1]-l[1],dp[1][1]=r[1]-1;
    for(int i=2;i<=n;i++)
    {
        int le=l[i],ri=r[i];
        int length=abs(le-ri)+1;
        dp[i][0]=min(dp[i-1][0]+abs(ri-l[i-1])+length,dp[i-1][1]+abs(r[i-1]-ri)+length);
        dp[i][1]=min(dp[i-1][0]+abs(le-l[i-1])+length,dp[i-1][1]+abs(r[i-1]-le)+length);
    }
    int ans=min(dp[n][0]+abs(n-l[n]),dp[n][1]+abs(n-r[n]));
    cout<<ans;
}