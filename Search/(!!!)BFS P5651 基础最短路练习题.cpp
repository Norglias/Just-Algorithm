#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
typedef pair<ll,int> PAIR;
const int maxn=200100;
const int MAXN=20020;

int n,m,q;
int dis[maxn];bool ju[maxn];
struct node
{
    int v;ll w;
};
vector<node>grasp[maxn];


void dfs(int start)
{
    queue<int>que;
    que.push(start);
    dis[start]=0;
    while (!que.empty())
    {
        int cur=que.front();
        que.pop();
        
        ju[cur]=true;
        for(auto &a:grasp[cur])
        {
            if(!ju[a.v])
            {
                ju[a.v]=true;
                dis[a.v]=dis[cur]^a.w;
                que.push(a.v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        grasp[u].push_back({v,w});
        grasp[v].push_back({u,w});
    }
    dfs(1);
    for(int i=1;i<=q;i++)
    {
        int b,e;cin>>b>>e;
        cout<<(dis[b]^dis[e])<<"\n";
    }
}