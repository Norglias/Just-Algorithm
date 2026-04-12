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

int n,x;
struct node
{
    int lo,wi,cx;
};node qwq[10010];
int dp[10010];

signed main()
{
    IOS;CT;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        int x1,x2,x3;cin>>x1>>x2>>x3;
        qwq[i].lo=x1,qwq[i].wi=x2,qwq[i].cx=x3;
    }
    
    for(int i=1;i<=n;i++)
    {
        int lose=qwq[i].lo,win=qwq[i].wi,curx=qwq[i].cx;
        for(int j=x;j>=0;j--)
        {
            if(j>=curx)
            dp[j]=max(dp[j]+lose,dp[j-curx]+win);
            else
            dp[j]=dp[j]+lose;
        }
    }
    int ans=0;
    for(int i=0;i<=x;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans*5;
    
}