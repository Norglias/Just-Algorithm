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
const int mod=1e15+1;
const int ppp=131;

int t;
int tree[maxn][2];
int idx;

void init()
{
    for(int i=0;i<=idx;i++)
    tree[i][0]=tree[i][1]=0;
}

void insert(int x)
{
    int p=0;
    for(int i=31;i>=0;i--)
    {
        int cur=(x>>i)&1;
        if(tree[p][cur]==0)
        tree[p][cur]=++idx;

        p=tree[p][cur];
    }
}

int query(int x)
{
    int p=0,res=0;
    for(int i=31;i>=0;i--)
    {
        int cur=(x>>i)&1;
        int op=cur^1;
        if(tree[p][op])
        {
            res+=(1<<i);
            p=tree[p][op];
        }
        else
        p=tree[p][cur];
    }
    return res;
}


signed main()
{
    IOS;CT;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;cin>>n;
        init();
        vector<int>num(n+1);
        idx=0;
        for(int j=1;j<=n;j++)
        {
            cin>>num[j];
            insert(num[j]);
        }
        int ans=-INF;
        for(int j=1;j<=n;j++)
        {
            ans=max(ans,query(num[j]));
        }   
        cout<<ans<<"\n";
    }
   
    
}