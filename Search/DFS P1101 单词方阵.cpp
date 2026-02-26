#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n;
char qwq[1000][1000];
char ans[105][105];
bool judge[105][105];

int dx[]={0,0,1,0,-1,-1,1,1,-1};
int dy[]={0,1,0,-1,0,-1,1,-1,1};
char word[]=" yizhong";

int dfs(int x,int y,int pos,int dir)
{
    if(pos==7)
    {
        return 1;
    }
    if(judge[x][y])
    return 0;
    judge[x][y]=1;


    int tx=x+dx[dir];
    int ty=y+dy[dir];
    if(qwq[tx][ty]==word[pos+1])
    {
        int check=dfs(tx,ty,pos+1,dir);
        if(check)
        {
            ans[tx][ty]=word[pos+1];
            return 1;
        }
    }
    
    return 0;
}


signed main()
{
    cin>>n;
    memset(ans,'*',sizeof(ans));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>qwq[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(qwq[i][j]=='y')
            {
                memset(judge,0,sizeof(judge));
                int c=0;
                for(int k=1;k<=8;k++)
                {
                    judge[i][j]=0;
                    c=dfs(i,j,1,k);
                    if(c==1)
                    break;
                }
                if(c)
                ans[i][j]='y';
            }
        }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<ans[i][j];
        cout<<"\n";
    }
}