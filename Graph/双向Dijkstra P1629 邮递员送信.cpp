#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;
typedef pair<ll,int> PAIR;
int n,m;
ll dis1[maxn],dis2[maxn];bool ju[maxn];

struct edge
{
    int v,w;
};
vector<edge>qwq1[maxn];
vector<edge>awa[maxn];

void solve(int x,vector<edge>qwq[],ll dis[])
{
    memset(ju,0,sizeof(ju));
    for(int i=1;i<=n;i++)
    dis[i]=1e15;

    dis[x]=0;
    priority_queue<PAIR,vector<PAIR>,greater<PAIR>>pr_q;
    pr_q.push({0,x});

    while (!pr_q.empty())
    {
        PAIR top=pr_q.top();
        pr_q.pop();

        int po=top.second;
        if(ju[po]==true)
        continue;
        ju[po]=true;

        for(auto &awa:qwq[po])
        {
            int pox=awa.v;
            ll pow=awa.w;
            if(dis[po]+pow<dis[pox])
            dis[pox]=dis[po]+pow;
            pr_q.push({dis[pox],pox});
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        qwq1[u].push_back({v,w});
        awa[v].push_back({u,w});
    }
    solve(1,qwq1,dis1);
    solve(1,awa,dis2);
    ll sum1=0;
    for(int i=2;i<=n;i++)
    sum1+=dis1[i]+dis2[i];

    cout<<sum1;
}