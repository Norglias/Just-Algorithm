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
const int mod=1e6+7;
const int ppp=131;

int n,t;
bool timemark[50];
bool mark=0;
struct node{
    int t,d,l;
};
node qwq[maxn];

void dfs(int pos,int depth,int curt)
{
    if(mark)return;
    if(curt>qwq[pos].d+qwq[pos].t)
    {
        return;
    }

    curt=max(curt,qwq[pos].t)+qwq[pos].l;
    if(depth==n)
    {
        mark=1;
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(timemark[i]==0&&i!=pos)
        {
            timemark[i]=1;
            dfs(i,depth+1,curt);
            timemark[i]=0;
        }
        
    }

}

signed main()
{
    IOS;CT;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x1,x2,x3;cin>>x1>>x2>>x3;
            qwq[i].t=x1,qwq[i].d=x2,qwq[i].l=x3;
        }
        mark=0;
        memset(timemark, 0, sizeof(timemark));
        for(int i=1;i<=n;i++)
        {
            timemark[i]=1;
            dfs(i,1,0);
            timemark[i]=0;
        }
        if(mark)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }

}