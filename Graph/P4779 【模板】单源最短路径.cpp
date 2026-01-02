#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

typedef pair<ll,int> PAIR;
ll dis[maxn];
bool root[maxn];
int n,m,s;

struct edge
{
    int to,w;
};
//邻接表
vector<edge>qwq[maxn];

void solve(int st)
{
    for(int i=1;i<=n;i++)
    dis[i]=1e15;

    dis[st]=0;
    priority_queue<PAIR,vector<PAIR>,greater<PAIR>> pr_q;
    pr_q.push({0,st});

    while (!pr_q.empty())
    {
        PAIR top=pr_q.top();
        pr_q.pop();

        ll u=top.second;

        if(root[u]==true)
        continue;
        root[u]=true;

        for(auto &x:qwq[u])
        {
            int ux=x.to;
            ll wx=x.w;
            if(dis[u]+wx<dis[ux])
            dis[ux]=dis[u]+wx;
            pr_q.push({dis[ux],ux});
        }
    }
}


int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        qwq[u].push_back({v,w});
    }
    solve(s);
    for(int i=1;i<=n;i++)
    cout<<dis[i]<<" ";

    return 0;
}   