#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,m,ans=INF;
char maap[500][500];
bool check[500][500];
bool letter[30];

int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};
int sx,sy;

struct door
{
    int sx,sy,ex,ey;
};

struct awa
{
    int x,y,w;
};

vector<door>qwq(30);

void bfs()
{
    queue<awa>q;
    q.push({sx,sy,0});
    check[sx][sy]=1;
    while(!q.empty())
    {
        awa top=q.front();
        q.pop();

        int x=top.x,y=top.y,w=top.w;
        // cout<<x<<" "<<y<<" "<<w<<"\n";
        if(maap[x][y]=='=')
        {
            cout<<w;
            return;
        }
        if(maap[x][y]>='A'&&maap[x][y]<='Z')
        {
            int pos=maap[x][y]-'A'+1;
            int s_x=qwq[pos].sx,s_y=qwq[pos].sy,e_x=qwq[pos].ex,e_y=qwq[pos].ey;
            if(x==s_x&&y==s_y)
            {
                x=e_x,y=e_y;
            }
            else if(x==e_x&&y==e_y)
            {
                x=s_x,y=s_y;
            }
        }
        for(int i=1;i<=4;i++)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];

            if(tx<1||ty<1||tx>n||ty>m||maap[tx][ty]=='#'||check[tx][ty])
            continue;
            
            int rx=tx,ry=ty;
            check[rx][ry]=1;
            q.push({rx,ry,w+1});
            
        }
    }
}

signed main()
{
    cin>>n>>m;
    string qqq;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>maap[i][j];
            if(maap[i][j]=='@')
            sx=i,sy=j;

            if(maap[i][j]>='A'&&maap[i][j]<='Z')
            {
                int pos=maap[i][j]-'A'+1;
                if(!letter[pos])
                {
                    letter[pos]=1;
                    qwq[pos].sx=i;qwq[pos].sy=j;
                }
                else
                {
                    qwq[pos].ex=i;qwq[pos].ey=j;
                }
            }
        }
    }
    bfs();
    
}