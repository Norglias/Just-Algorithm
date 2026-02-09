#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

ll n,h,ans,m;
int bo[maxn];ll dis[maxn];bool ju[maxn];

struct edge
{
    ll v,w;
};
vector<edge>graph[maxn];


void solve(int s)
{
    for(int i=0;i<=m-1;i++)
    dis[i]=INF;
    dis[s]=0;

    priority_queue<PAIR,vector<PAIR>,greater<PAIR>>pr_q;
    pr_q.push({0,s});

    while(!pr_q.empty())
    {
        PAIR cur=pr_q.top();
        pr_q.pop();

        int u=cur.second;
        if(ju[u])
        continue;
        ju[u]=1;

        for(auto &x:graph[u])
        {
            ll w=x.w;int v=x.v;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pr_q.push({dis[v],v});
            }
        }
    }
}


signed main()
{
    cin>>n>>h;
    h-=1;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x)//注意按键数字为0的情况,需要排除
        bo[++cnt]=x;
    }
    n=cnt;
    sort(bo+1,bo+n+1);
    if(!n)//特判!!
    {
        cout<<1;
        return 0;
    }
    m=bo[1];
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int awa=(i+bo[j])%m;
            graph[i].push_back({awa,bo[j]});
        }
    }
    solve(0);

    for(int i=0;i<m;i++)
    {
        if(dis[i]<=h)
        ans+=(h-dis[i])/m+1;
    }
    cout<<ans;
}