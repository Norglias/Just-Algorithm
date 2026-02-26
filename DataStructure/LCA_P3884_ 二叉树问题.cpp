#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,depth[maxn],maxdepth=-1,maxw=-1,mode,ans1,ans2,ans;
int mark[maxn];
int fa[maxn][25];
vector<int>tree[maxn];

void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    maxdepth=max(maxdepth,depth[u]);
    fa[u][0]=p;
    for(int i=1;i<=20;i++)
    fa[u][i]=fa[fa[u][i-1]][i-1];

    for(int v:tree[u])
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
        {
            u=fa[u][i];
            if(mode)
            ans1+=(1<<i);
            else
            ans1+=(1<<i)*2;
        }
        
    }
    if(u==v)return ans1;
    for(int i=20;i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
            ans2+=(1<<i)*3;
        }
    }
    return ans1+ans2+3;
}

signed main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    int u,v;cin>>u>>v;
    if(depth[u]>=depth[v])
    mode=0;
    else
    mode=1;
    
    for(int i=1;i<=n;i++)
    {
        mark[depth[i]]++;
        maxw=max(maxw,mark[depth[i]]);
    }
    cout<<maxdepth<<"\n"<<maxw<<"\n"<<lca(u,v);
    

}