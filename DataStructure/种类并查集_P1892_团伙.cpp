#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=212370440130137957ll;
const int ppp=131;

int n,m;
int fa[maxn],enemy[maxn];

int find(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        char p;cin>>p;
        int u,v;cin>>u>>v;
        if(p=='E')
        {
            if(enemy[u]==0)
            enemy[u]=v;
            else
            {
                int ev=enemy[u];
                fa[find(ev)]=find(v);
            }
            if(enemy[v]==0)
            enemy[v]=u;
            else
            {
                int ev=enemy[v];
                fa[find(ev)]=find(u);
            }
        }
        else
        {
            fa[find(u)]=find(v);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    if(fa[i]==i)
    ans++;
    cout<<ans;
}