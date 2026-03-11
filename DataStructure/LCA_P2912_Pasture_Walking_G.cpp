#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,q;
int fa[maxn][25],depth[maxn],dist[maxn];
struct node
{
    int v,w;
};
vector<node>tree[maxn];

void dfs(int u,int p,int w)
{
    depth[u]=depth[p]+1;
    dist[u]=dist[p]+w;
    fa[u][0]=p;
    for(int i=1;i<=20;i++)
    fa[u][i]=fa[fa[u][i-1]][i-1];

    for(auto no:tree[u])
    {
        int v=no.v,ww=no.w;
        if(v!=p)
        dfs(v,u,ww);
    }
}

int lca(int u,int v)
{
    if(depth[u]<depth[v])
    swap(u,v);

    for(int i=20;i>=0;i--)
    {
        if(depth[fa[u][i]]>=depth[v])
        {
            u=fa[u][i];
        }
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
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    dfs(1,0,0);
    for(int i=1;i<=q;i++)
    {
        int u,v;cin>>u>>v;
        int ans=dist[u]+dist[v]-2*dist[lca(u,v)];
        cout<<ans<<"\n";
    }
}