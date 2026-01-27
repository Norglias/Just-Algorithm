#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;

int n,m;
int ans[405][405];
bool ju[405][405];
queue<pair<int,int>>qu;
int dx[]={-2,-2,2,2,1,-1,1,-1};
int dy[]={-1,1,-1,1,2,-2,-2,2};


int main()
{
    cin>>n>>m;
    int x,y;cin>>x>>y;
    memset(ans,-1,sizeof(ans));
    ju[x][y]=true;ans[x][y]=0;
    qu.push({x,y});
    while (!qu.empty())
    {
        for(int i=0;i<8;i++)
        {
            int tx=qu.front().first+dx[i];
            int ty=qu.front().second+dy[i];
            if(tx>0&&tx<=n&&ty>0&&ty<=m&&ju[tx][ty]==false)
            {
                ju[tx][ty]=true;
                ans[tx][ty]=ans[qu.front().first][qu.front().second]+1;
                qu.push({tx,ty});
            }
        }
        qu.pop();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}