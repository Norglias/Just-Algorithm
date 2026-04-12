#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;

int t;
int n,m;
vector<int>qwq[maxn];
int depth[maxn];
bool check[maxn];
int res[maxn];

int bfs(int p)
{
    memset(check, 0, sizeof(check));
    int ans=-INF;
    queue<int>q;
    q.push(p);
    depth[p]=1;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(check[top])
        continue;
        check[top]=1;
        for(auto v:qwq[top])
        {
            depth[v]=depth[top]+1;
            if(ans<depth[v])
            {
                ans=depth[v];
            }
            q.push(v);
        }
    }
    return ans;
}
int tar;
bool c;
void dfs(int s,int depth)
{
    if(c)
    return;
    res[depth]=s;
    if(depth==tar)
    {
        c=1;
        return;
    }
    for(auto v:qwq[s])
    {
        dfs(v,depth+1);
    }
}

signed main()
{
    IOS;CT;
    cin>>n;
    if(n==1)
    {
        cout<<"1\n0";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;cin>>x;
            qwq[i].push_back(x);
        }
        sort(qwq[i].begin(),qwq[i].end());
    }
    int maxpos=-1,maxx=-INF;
    for(int i=0;i<n;i++)
    {
        int cur=bfs(i);
        if(cur>maxx)
        {
            maxx=cur;
            maxpos=i;
        }
    }
    tar=maxx;
    cout<<maxx<<"\n";
    dfs(maxpos,1);
    bool asa=0;
    for(int i=1;i<=tar;i++)
    {
        if(asa==0)
        cout<<res[i],asa=1;
        else
        cout<<" "<<res[i];
    }
}