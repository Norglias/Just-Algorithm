#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n;
int peo[maxn];
int dis[maxn];bool check[1000];
struct node
{
    int v,w;
};
vector<node>tree[maxn];

void solve(int s)
{
    memset(check,0,sizeof(check));
    for(int i=1;i<=n;i++)
    dis[i]=INF;

    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(check[top])
        continue;
        check[top]=1;
        int ple=peo[top];
        for(auto &x:tree[top])
        {
            int v=x.v,w=x.w;
            dis[v]=min(dis[v],dis[top]+w);
            q.push(v);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r,w;
        cin>>w>>l>>r;
        peo[i]=w;
        if(l!=0)
        {
            tree[i].push_back({l,1});
            tree[l].push_back({i,1});
        }
        if(r!=0)
        {
            tree[i].push_back({r,1});
            tree[r].push_back({i,1});
        }
    }
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        solve(i);
        int sum=0;
        for(int j=1;j<=n;j++)
        sum+=dis[j]*peo[j];
        ans=min(ans,sum);
    }
    cout<<ans;
}