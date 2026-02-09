#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,m,t;
int sx,sy,ex,ey;
bool qwq[100][100];
bool awa[100][100];
int cnt;

int dx[]={0,-1,0,1,0};
int dy[]={0,0,1,0,-1};

void dfs(int x,int y)
{
    if(qwq[x][y])
    return;
    if(x==ex&&y==ey)
    {
        cnt++; 
        return;
    }
    awa[x][y]=1; //别忘了标记起点
    for(int i=1;i<=4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&awa[tx][ty]==0)
        {
            awa[tx][ty]=1;
            dfs(tx,ty);
            awa[tx][ty]=0;
        }
    }
}

signed main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>ex>>ey;

    for(int i=1;i<=t;i++)
    {
        int x,y;cin>>x>>y;
        qwq[x][y]=1;
    }
    if(qwq[ex][ey])
    {
        cout<<'0';
        return 0;
    }
    dfs(sx,sy);
    cout<<cnt;
}