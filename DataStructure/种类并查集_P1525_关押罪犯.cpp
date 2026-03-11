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

int n,m,ans;
int fa[maxn];
int enemy[maxn];

int find(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}
struct edge{
    int u,v,w;
};
vector<edge>qwq;

bool cmp(edge a,edge b)
{
    return a.w>b.w;
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
        int u,v,w;cin>>u>>v>>w;
        qwq.push_back({u,v,w});
    }
    sort(qwq.begin(),qwq.end(),cmp);
    int cnt=n;
    for(auto x:qwq)
    {
        int u=x.u,v=x.v,w=x.w;
        if(find(u)==find(v))
        {
            ans=max(ans,w);
            continue;
        }
        if(enemy[u]==0)
        enemy[u]=v;
        else
        {
            int vvv=enemy[u];
            fa[find(vvv)]=find(v);
            cnt--;
        }
        if(enemy[v]==0)
        enemy[v]=u;
        else
        {
            int vvv=enemy[v];
            fa[find(vvv)]=find(u);
            cnt--;
        }
    }
    cout<<ans;
}