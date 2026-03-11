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

int n,m;
int s[1010],mark[1010],in[1010],dis[1010];
int qwq[1010][1010];


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        memset(s,0,sizeof(s));
        memset(mark,0,sizeof(mark));
        
        for(int k=1;k<=x;k++)
        {
            cin>>s[k];
            mark[s[k]]=1;
        }
        for(int k=1;k<=n;k++)
        {
            if(mark[k]||k>s[x]||k<s[1])
            continue;
            for(int j=1;j<=x;j++)
            {
                qwq[k][s[j]]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(qwq[i][j])
        in[j]++;
    queue<int>q;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        dis[i]=1;
        if(in[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(int x=1;x<=n;x++)
        {
            if(qwq[top][x]==1)
            {
                dis[x]=max(dis[x],dis[top]+1);
                ans=max(ans,dis[x]);
                in[x]--;
                if(in[x]==0)
                q.push(x);
            }
            
        }
    }
    cout<<ans;
}

