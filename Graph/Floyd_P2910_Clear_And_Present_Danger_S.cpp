#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,m;
int d[200][200];
int path[maxn];
signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            d[i][j]=0;
            else
            d[i][j]=INF;
        }
    for(int i=1;i<=m;i++)
    {
        cin>>path[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>d[i][j];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(d[i][k]!=INF&&d[k][j]!=INF)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    
    int ans=0;
    for(int i=1;i<m;i++)
    {
        ans+=d[path[i]][path[i+1]];
    }
    cout<<ans;
}