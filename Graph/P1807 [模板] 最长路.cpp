#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const int INF=1e9;
const ull ppp=131;

int tow[maxn];int dist[maxn];
vector<pair<int,int>>graph[maxn];

int main()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        graph[u].push_back({v,w});
        tow[v]++;
    }
    queue<int>que;
    for(int i=1;i<=n;i++)
    dist[i]=-INF;
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        if(tow[i]==0)
        que.push(i);
    }

    while(!que.empty())
    {
        int u=que.front();
        que.pop();

        for(auto &x:graph[u])
        {
            int v=x.first;int w=x.second;
            if(dist[u]!=-INF)
            dist[v]=max(dist[v],dist[u]+w);
            
            tow[v]--;
            if(tow[v]==0)
            que.push(v);
        }
    }

    if(dist[n]==-INF)
    cout<<"-1";
    else
    cout<<dist[n];
}