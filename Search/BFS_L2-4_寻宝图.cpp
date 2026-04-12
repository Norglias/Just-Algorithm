#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,m;
int cnt1,cnt2;
vector<vector<int>>maap;
vector<vector<int>>check;
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1};

int bfs(int x,int y)
{
    queue<PAIR>q;
    q.push({x,y});
    check[x][y]=1;
    bool has=0;
    while(!q.empty())
    {
        PAIR top=q.front();
        q.pop();
        int cx=top.first,cy=top.second;
        if(maap[cx][cy]>1)
        has=1;

        for(int i=1;i<=4;i++)
        {
            int tx=cx+dx[i];
            int ty=cy+dy[i];

            if(tx<1||tx>n||ty<1||ty>m||maap[tx][ty]==0||check[tx][ty])
            continue;
            check[tx][ty]=1;
            q.push({tx,ty});
        }
    }
    return has;
}


signed main()
{
    IOS;CT;
    cin>>n>>m;
    maap.assign(n+10,vector<int>(m+10,0));
    check.assign(n+10,vector<int>(m+10,0));
    for(int i=1;i<=n;i++)
    {
        string qwq;cin>>qwq;
        for(int j=0;j<m;j++)
        {
            maap[i][j+1]=(qwq[j]-'0');
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(check[i][j])
            continue;
            if(maap[i][j])
            {
                cnt2+=bfs(i,j);
                cnt1++;
            }
        }
    }
    cout<<cnt1<<" "<<cnt2;
}