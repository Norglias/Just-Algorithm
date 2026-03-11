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

int n,m,cnt;
vector<int>graph[maxn];
int f[maxn];
bool check[maxn];

void dfs(int s,int begin)
{
    if(f[s])
    {
        return;
    }
    f[s]=max(f[s],begin);
    for(auto x:graph[s])
    dfs(x,begin);
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[v].push_back(u);
    }
    for(int i=n;i;i--)
    {
        dfs(i,i);
    }
    for(int i=1;i<=n;i++)
    cout<<f[i]<<" ";

}

