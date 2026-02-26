#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,m,s;
vector<int>graph[maxn];

int depth[maxn];
int fa[maxn][25];

void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    fa[u][0]=p;

    for(int i=1;i<=20;i++)
    fa[u][i]=fa[fa[u][i-1]][i-1];

    for(int v:graph[u])
    {
        if(v!=p)
        dfs(v,u);
    }
}

int lca(int u,int v)
{
    if(depth[u]<depth[v])
    swap(u,v);

    for(int i=20;i>=0;i--)
    {
        if(depth[fa[u][i]]>=depth[v])
        u=fa[u][i];
    }
    if(u==v)return u;
    for(int i=20;i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
}