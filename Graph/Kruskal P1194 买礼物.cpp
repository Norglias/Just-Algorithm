#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

int in[5000][5000];
bool judge[maxn];
int fa[MAXN];
struct edge
{
    int u,v,w;
};
vector<edge>qwq;
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}


inline int find(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;cin>>a>>b;

    for(int i=1;i<=b;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {
            cin>>in[i][j];
            if(in[i][j]!=0&&j>i)
            {
                qwq.push_back({i,j,in[i][j]});
            }
        }
    }
    if(qwq.empty())
    {
        cout<<a*b;
        return 0;
    }
    sort(qwq.begin(),qwq.end(),cmp);
    int cnt=b-1,ans=0;
    for(auto x:qwq)
    {
        if(find(x.u)!=find(x.v)&&x.w<=a)
        {
            fa[find(x.u)]=find(x.v);
            ans+=x.w;
            cnt--;
        }

        if(cnt==0)
        break;
    }
    for(int i=1;i<=b;i++)
    {
        if(!judge[find(i)])
        {
            ans+=a;
            judge[find(i)]=true;
        }
    }
    cout<<ans;
    return 0;
}

