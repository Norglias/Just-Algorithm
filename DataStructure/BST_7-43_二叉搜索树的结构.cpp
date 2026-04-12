#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
const int mod=1e9+7;
const int ppp=131;


int n;
unordered_map<int,int>sepos;
int idx=1;
struct tree
{
    int l,r,w=-INF,depth;
};
tree qwq[maxn];

void insert(int pos,int x,int d)
{
    if(qwq[pos].w==-INF)
    {
        qwq[pos].w=x;
        qwq[pos].depth=d;
        return;
    }
    if(x<qwq[pos].w)
    {
        if(qwq[pos].l==0)
        {
            idx++;
            qwq[idx].w=x;
            qwq[idx].depth=d+1;
            qwq[pos].l=idx;
        }
        else
        insert(qwq[pos].l,x,d+1);   
    }
    else if(x>qwq[pos].w)
    {
        if(qwq[pos].r==0)
        {
            idx++;
            qwq[idx].w=x;
            qwq[idx].depth=d+1;
            qwq[pos].r=idx;
        }
        else
        insert(qwq[pos].r,x,d+1);
    }
}


int findb(int x1,int x2)
{
    for(int i=1;i<=n;i++)
    {
        if((qwq[i].l==x1&&qwq[i].r==x2)||(qwq[i].r==x1&&qwq[i].l==x2))
        return 1;
    }
    return 0;
}


signed main()
{
    IOS;CT;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        insert(1,x,1);
    }
    for(int i=1;i<=n;i++)
    {
        sepos[qwq[i].w]=i;
    }
    int m;cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        string a1,a2,a3,a4,a5,a6;
        cin>>a1;
        if(a1=="is")
        {
            cin>>a2>>a3;
            if(a3=="parent")
            {
                cin>>a5;
                int b;cin>>b;
                if(sepos[x]==0||sepos[b]==0)
                {
                    cout<<"No\n";
                    continue;
                }
                if(qwq[sepos[x]].l==sepos[b]||qwq[sepos[x]].r==sepos[b])
                cout<<"Yes\n";
                else
                cout<<"No\n";
            }
            else if(a3=="left")
            {
                cin>>a5>>a6;
                int b;cin>>b;
                if(sepos[x]==0||sepos[b]==0)
                {
                    cout<<"No\n";
                    continue;
                }
                if(qwq[sepos[b]].l==sepos[x])
                cout<<"Yes\n";
                else
                cout<<"No\n";
            }
            else if(a3=="right")
            {
                cin>>a5>>a6;
                int b;cin>>b;
                if(sepos[x]==0||sepos[b]==0)
                {
                    cout<<"No\n";
                    continue;
                }
                if(qwq[sepos[b]].r==sepos[x])
                cout<<"Yes\n";
                else
                cout<<"No\n";
            }
            else if(a3=="root")
            {
                if(qwq[1].w==x)
                cout<<"Yes\n";
                else
                cout<<"No\n";
            }
        }
        else if(a1=="and")
        {
            int b;cin>>b;
            cin>>a2>>a3;
            if(a3=="siblings")
            {
                if(sepos[x]==0||sepos[b]==0)
                {
                    cout<<"No\n";
                    continue;
                }
                int r=findb(sepos[x],sepos[b]);
                if(r)
                cout<<"Yes\n";
                else
                cout<<"No\n";
            }
            else if(a3=="on")
            {
                cin>>a4>>a5>>a6;
                if(sepos[x]==0||sepos[b]==0)
                {
                    cout<<"No\n";
                    continue;
                }
                if(qwq[sepos[x]].depth==qwq[sepos[b]].depth)
                cout<<"Yes\n";
                else
                cout<<"No\n";
            }

        }
    }
}