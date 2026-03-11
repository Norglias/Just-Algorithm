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

int k,n,m;
int cow[maxn];
bool check[1010];int mark[maxn];
vector<int>graph[maxn];

void dfs(int u)
{
    if(check[u])
    return;
    check[u]=1;
    mark[u]++;
    for(auto v:graph[u])
    {
        dfs(v);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>n>>m;
    for(int i=1;i<=k;i++)
    {
        cin>>cow[i];
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
    }
    for(int i=1;i<=k;i++)
    {
        memset(check,0,sizeof(check));
        dfs(cow[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    if(mark[i]==k)
    ans++;
    cout<<ans;

}

