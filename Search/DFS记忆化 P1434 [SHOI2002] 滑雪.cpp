#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int n,m,len;
int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};
int maap[105][105];
bool judge[105][105];
int longpath[105][105];
int maxx=-1;

int dfs(int x,int y)
{
    if(longpath[x][y])
    return longpath[x][y];
    
    len=1;
    for(int i=1;i<=4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<1||tx>n||ty<1||ty>m)
        continue;
        if(maap[tx][ty]<maap[x][y])
        {
            len=max(len,dfs(tx,ty)+1);
        }
    }
    return longpath[x][y]=len;
}


signed main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>maap[i][j];
        }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            maxx=max(maxx,dfs(i,j));
        }
    cout<<maxx;
}