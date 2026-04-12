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

int n,m;
int cnt;
int dfn[maxn],low[maxn],timer;
vector<int>qwq[maxn];
bool check[maxn];

void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++timer;
    int son=0;
    for(auto v:qwq[u])
    {
        if(v==fa)
        continue;

        if(dfn[v]==0)
        {
            son++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(fa!=0&&low[v]>=dfn[u])
            {
                check[u]=1;
                // cnt++;
            }
        }
        else
        low[u]=min(low[u],dfn[v]);
    }
    if(fa==0&&son>=2)
    {
        check[u]=1;
        // cnt++;
    }
}

signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        qwq[u].push_back(v);
        qwq[v].push_back(u);
    }    
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
        tarjan(i,0);
    }
    for(int i=1;i<=n;i++)
    if(check[i])
    cnt++;
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++)
    if(check[i])
    cout<<i<<" ";
}