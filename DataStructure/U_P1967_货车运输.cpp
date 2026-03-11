#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,m,q,depth[maxn],fa[maxn][25],f[maxn];
struct edge
{
    int u,v,w;
};vector<edge>tree[maxn];
edge awa[maxn];

struct st
{
    int u,v,w;
};vector<st>qwq[maxn];

int find(int x)
{
    if(f[x]==x)
    return x;
    else
    return f[x]=find(f[x]);
}

void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    fa[u][0]=p;
    for(int i=1;i<=20;i++)
    fa[u][i]=fa[fa[u][i-1]][i-1];

    for(auto node:tree[u])
    {
        int v=node.v;
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
    if(u==v)return v;
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

bool cmp(edge a,edge b)
{
    return a.w>b.w;
}

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
        awa[i].u=u;awa[i].v=v;awa[i].w=w;
    }
    sort(awa+1,awa+m,cmp);
    
    int cnt=n;
    for(int i=1;i<=n;i++)
    f[i]=i;
    for(auto x:awa)
    {
        int xu=find(x.u);
        int xv=find(x.v);
        if(xu!=xv)
        {
            f[xu]=xv;
            cnt--;
        }
        if(cnt==1)
        break;
    }


    int q;cin>>q;
    for(int i=1;i<=q;i++)
    {
        
    }
}