#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=1000000ll;
const int ppp=131;

int n,t;
struct edge
{
    int u,v,op;
};

bool cmp(edge a,edge b)
{
    return a.op>b.op;
}

inline int find(int x,unordered_map<int,int>&fa)
{
    if(fa[x]==x)
    return x;
    else 
    return fa[x]=find(fa[x],fa);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        unordered_map<int,int>fa;
        vector<edge>qwq;
        int n;cin>>n;
        bool check=0;
        for(int j=1;j<=n;j++)
        {
            int u,v,op;cin>>u>>v>>op;
            fa[u]=u;fa[v]=v;
            qwq.push_back({u,v,op});
        }
        sort(qwq.begin(),qwq.end(),cmp);
        for(auto x:qwq)
        {
            int u=x.u,v=x.v;
            if(x.op==1)
            {
                fa[find(u,fa)]=find(v,fa);
            }
            else
            {
                if(find(v,fa)==find(u,fa))
                {
                    check=1;
                    break;
                }
            }
        }
        if(check)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
    
}

