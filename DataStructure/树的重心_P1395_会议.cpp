#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;

int t;
int n,m,minn;
vector<int>qwq[maxn];
int siz[maxn];
int awa[maxn];

void dfs(int u,int p)
{
    siz[u]=1;
    int maxx=0;
    for(int v:qwq[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            siz[u]+=siz[v];
            maxx=max(maxx,siz[v]);
        }
    }
    maxx=max(maxx,n-siz[u]);
    awa[u]=maxx;
}

int sum=0;
int check[50010];
void dfs1(int s,int dis)
{
    sum+=dis;
    check[s]=1;
    if(qwq[s].empty())
    {
        return;
    }
    for(auto x:qwq[s])
    {
        if(check[x]==0)
        dfs1(x,dis+1);
    }
}

signed main()
{
    IOS;CT;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        qwq[u].push_back(v);
        qwq[v].push_back(u);
    }
    dfs(1,0);
    int minn=INF;
    for(int i=1;i<=n;i++)
    {
        if(minn>awa[i])
        {
            minn=awa[i];
        }
    }
    vector<int>res;
    for(int i=1;i<=n;i++)
    {
        if(awa[i]==minn)
        res.push_back(i);
    }
    int ans=INF,tarpos=0;
    for(auto x:res)
    {
        dfs1(x,0);
        if(ans>sum)
        {
            tarpos=x;
            ans=sum;
        }
    }
    cout<<tarpos<<" "<<ans;
}