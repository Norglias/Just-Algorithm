#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;

int n;
int maaap[50][50];
bool ju[50][50];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

queue<pair<int,int>>que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>maaap[i][j];
    que.push({0,0});
    while (!que.empty())
    {
        for(int i=0;i<4;i++)
        {
            int tx=que.front().first+dx[i];
            int ty=que.front().second+dy[i];
            if(maaap[tx][ty]==0&&tx>=0&&tx<=n+1&&ty>=0&&ty<=n+1)
            {
                maaap[tx][ty]=3;
                que.push({tx,ty});
            }
        }
        que.pop();
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(maaap[i][j]==3)
            maaap[i][j]=0;
            else if(maaap[i][j]==0)
            maaap[i][j]=2;
            cout<<maaap[i][j]<<" ";
        }
        cout<<"\n";
    }

}