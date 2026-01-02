#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

int n,m,s,t;
int fa[maxn];

struct edge
{
    int u,v,w;
};
vector<edge>city;

int find(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}

bool cmp(edge x1,edge x2)
{
    return x1.w<x2.w;
}

int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        city.push_back({u,v,w});
    }
    for(int i=1;i<=n;i++)
    fa[i]=i;
    int ans=0;
    sort(city.begin(),city.end(),cmp);
    for(auto &a:city)
    {
        if(find(s)==find(t))
        {
            cout<<ans;
            return 0;
        }
        int xu=find(a.u);
        int xv=find(a.v);
        if(xu!=xv)
        {
            fa[xu]=xv;
            ans=max(ans,a.w);
        }
    }
    cout<<ans;  
}