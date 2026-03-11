#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=80112002;
const int ppp=131;

int n,m,cnt;
vector<int>graph[maxn];
int tow[maxn],out[maxn],dis[maxn];
int ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        tow[v]++;
        out[u]++;
    }

    queue<int>q;
    

    for(int i=1;i<=n;i++)
    {
        if(tow[i]==0)
        {
            dis[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(auto x:graph[top])
        {
            dis[x]=(dis[x]+dis[top])%mod;
            tow[x]--;
            if(tow[x]==0)
            q.push(x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(out[i]==0)
        cnt=(cnt+dis[i])%mod;
    }
    cout<<cnt;
    

}

