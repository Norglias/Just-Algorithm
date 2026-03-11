#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,q;
vector<int>tree[maxn];
int depth[maxn],fa[maxn][25];

void dfs(int u,int p)
{   
    depth[u]=depth[p]+1;
    fa[u][0]=p;

    for(int i=1;i<=20;i++)
    fa[u][i]=fa[fa[u][i-1]][i-1];

    for(auto v:tree[u])
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
    if(u==v)
    return u;
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

int dis(int a,int b)
{
    int l=lca(a,b);
    return abs(depth[l]-depth[a])+abs(depth[l]-depth[b]);
}

signed main()
{
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=q;i++)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;
        int ab=lca(a,b);int cd=lca(c,d);
        if(dis(a,cd)+dis(b,cd)==dis(a,b)||dis(c,ab)+dis(d,ab)==dis(c,d))
        cout<<"Y"<<"\n";
        else
        cout<<"N"<<"\n";
    }
}   