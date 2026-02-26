#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int m,ans;
int maap[500][500];
int step[500][500];
bool visited[500][500];
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1};

void bfs()
{
    queue<pair<int,int>>q;
    q.push({0,0});

    while(!q.empty())
    {
        pair<int,int>top=q.front();
        int x=top.first,y=top.second;
        q.pop();
        
        if(visited[x][y])
        continue;
        visited[x][y]=1;

        for(int i=1;i<=4;i++)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(tx<0||ty<0)
            continue;

            if(maap[tx][ty]==INF)
            {
                cout<<step[x][y]+1;
                return;
            }
            if(maap[tx][ty]>step[x][y]+1)
            {
                step[tx][ty]=step[x][y]+1;
                q.push({tx,ty});
            }
        }
    }
    cout<<"-1";
}


signed main()
{
    cin>>m;
    for(int i=0;i<=400;i++)
        for(int j=0;j<=400;j++)
        maap[i][j]=INF;

    for(int i=1;i<=m;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        for(int j=0;j<=4;j++)
        {
            int tx=x+dx[j];
            int ty=y+dy[j];
            if(tx<0||ty<0)
            continue;
            
            maap[tx][ty]=min(maap[tx][ty],t);
        }
    }
    if(maap[0][0]==0)
    {
        cout<<"-1";
        return 0;
    }
    else if(maap[0][0]==INF)
    {
        cout<<"0";
        return 0;
    }
    bfs();

}