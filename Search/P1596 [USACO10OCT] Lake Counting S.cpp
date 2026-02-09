#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int dx[]={0,-1,-1,0,1,1,1,0,-1};
int dy[]={0,0,1,1,1,0,-1,-1,-1};
int n,m,cnt;
string maap[105];
bool mark[105][105];

void dfs(int x,int y)
{
    for(int i=1;i<=8;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(maap[tx][ty]=='W'&&mark[tx][ty]==0)
        {
            mark[tx][ty]=1;
            dfs(tx,ty);
        }
    }
}

signed main()
{
    cin>>n>>m;
    string one="";
    for(int i=0;i<=m+1;i++)
    one+='.';

    maap[0]=maap[n+1]=one;
    for(int i=1;i<=n;i++)
    {
        string cur;cin>>cur;
        maap[i]='.'+cur+'.';
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maap[i][j]=='W'&&mark[i][j]==0)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}