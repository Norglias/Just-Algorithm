#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

typedef pair<int,ll> PAIR;
int n,m,s,t;
ll dis[maxn];bool ju[maxn];

struct edge
{
    int v,w;
};
vector<edge>qwq[maxn];


inline void solve(int bg)
{
    for(int i=1;i<=n;i++)
    dis[i]=1e15;

    dis[bg]=0;

    priority_queue<PAIR,vector<PAIR>,greater<PAIR>>pr_q;
    pr_q.push({0,bg});
    
    while (!pr_q.empty())
    {
        PAIR top=pr_q.top();
        pr_q.pop();
        int vv=top.second;
        if(ju[vv]==true)
        continue;
        ju[vv]=true;

        for(auto &x:qwq[vv])
        {
            int xv=x.v;ll xw=x.w;
            if(dis[vv]+xw<dis[xv])
            dis[xv]=dis[vv]+xw;
            pr_q.push({dis[xv],xv});
        }
    }
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        qwq[u].push_back({v,w});
        qwq[v].push_back({u,w});
    }
    solve(s);

    cout<<dis[t];
    return 0;
}