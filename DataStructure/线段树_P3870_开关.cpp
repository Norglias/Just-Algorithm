#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<double,double> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,m;
int a[maxn];

int tree[4*maxn],sum[4*maxn];
int lazy[4*maxn];

int ls(int p)
{return p<<1;}
int rs(int p)
{return p<<1|1;}

void up(int p)
{
    sum[p]=sum[ls(p)]+sum[rs(p)];
}

void down(int p,int len)
{
    if(lazy[p])
    {
        lazy[ls(p)]^=1;
        lazy[rs(p)]^=1;
        sum[ls(p)]=(len-(len>>1))-sum[ls(p)];
        sum[rs(p)]=(len>>1)-sum[rs(p)];
        lazy[p]=0;
    }
}


void update(int p,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    {
        sum[p]=(r-l+1)-sum[p];
        lazy[p]^=1;
        return;
    }
    down(p,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)update(ls(p),l,mid,L,R);
    if(R>mid)update(rs(p),mid+1,r,L,R);
    up(p);
}

int query(int p,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    return sum[p];

    down(p,r-l+1);
    int mid=(l+r)>>1;
    int ans=0;
    if(L<=mid)ans+=query(ls(p),l,mid,L,R);
    if(R>mid)ans+=query(rs(p),mid+1,r,L,R);
    return ans;
}

signed main()
{
    cin>>n>>m;
    // build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        int l,r;cin>>l>>r;
        if(op==0)
        {
            update(1,1,n,l,r);
        }
        else
        cout<<query(1,1,n,l,r)<<"\n";
    }
}