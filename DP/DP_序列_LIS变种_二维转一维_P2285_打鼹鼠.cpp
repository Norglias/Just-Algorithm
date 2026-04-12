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

int n,m;
struct node
{
    int x,y,ti;
};
node qwq[maxn];
int dp[maxn];

signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x1,x2,x3;cin>>x3>>x1>>x2;
        qwq[i].x=x1,qwq[i].y=x2,qwq[i].ti=x3;
        dp[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int ux=qwq[i].x,uy=qwq[i].y,ut=qwq[i].ti;
        for(int j=i+1;j<=m;j++)
        {
            int vx=qwq[j].x,vy=qwq[j].y,vt=qwq[j].ti;
            if(abs(ux-vx)+abs(uy-vy)<=abs(ut-vt))
            dp[j]=max(dp[j],dp[i]+1);
        }
    }
    int ans=-INF;
    for(int i=1;i<=m;i++)
    ans=max(ans,dp[i]);
    cout<<ans;

}