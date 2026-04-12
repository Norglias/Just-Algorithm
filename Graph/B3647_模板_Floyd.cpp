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
        int u,v,w;cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(d[i][k]!=INF&&d[k][j]!=INF)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<d[i][j]<<" ";
        cout<<"\n";
    }   
}