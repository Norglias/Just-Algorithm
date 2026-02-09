#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;


int n,m,cnt;
string maap[105];
bool mark[105][105];
int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};



void dfs(int x,int y)
{
    for(int i=1;i<=4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(maap[tx][ty]!='0'&&mark[tx][ty]==0)
        {
            mark[tx][ty]=1;
            dfs(tx,ty);
        }
    }
}

signed main()
{
    cin>>n>>m;
    string f;
    for(int i=0;i<=m+1;i++)
    f+='0';
    maap[0]=f;
    maap[n+1]=f;
    for(int i=1;i<=n;i++)
    {
        string cur;cin>>cur;
        maap[i]='0'+cur+'0';
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(maap[i][j]!='0'&&mark[i][j]==0)
            {
                mark[i][j]=1;
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}