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

int n,m;
int tree[4*maxn],lazy[4*maxn];
int num[maxn],qwq[maxn];

int ls(int p)
{return p<<1;}
int rs(int p)
{return p<<1|1;}

void up(int p)
{
    tree[p]=tree[ls(p)]+tree[rs(p)];
}

void down(int p,int len)
{
    if(lazy[p])
    {
        lazy[ls(p)]+=lazy[p];
        lazy[rs(p)]+=lazy[p];
        tree[ls(p)]+=lazy[p]*(len-(len>>1));
        tree[rs(p)]+=lazy[p]*(len>>1);
        lazy[p]=0;
    }
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        tree[p]=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);

    up(p);
}

void update(int p,int l,int r,int L,int R,int k)
{
    if(L<=l&&r<=R)
    {
        tree[p]+=k*(r-l+1);
        lazy[p]+=k;
        return;
    }
    down(p,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
    update(ls(p),l,mid,L,R,k);
    if(R>mid)
    update(rs(p),mid+1,r,L,R,k);

    up(p);
}

int query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    return tree[p];
    
    int ans=0;
    down(p,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
    ans+=query(ls(p),l,mid,L,R);
    if(R>mid)
    ans+=query(rs(p),mid+1,r,L,R);

    return ans;
}

signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>qwq[i];
    
    for(int i=1;i<=n;i++)
    {
        num[i]=qwq[i]-qwq[i-1];
        // cout<<num[i]<<"\n";
    }
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int l,r,k,d;
            cin>>l>>r>>k>>d;
            update(1,1,n,l,l,k);
            if(l+1<=r)update(1,1,n,l+1,r,d);
            if(r+1<=n)update(1,1,n,r+1,r+1,-(k+(r-l)*d));
        }
        else if(op==2)
        {
            int p;cin>>p;
            cout<<query(1,1,n,1,p)<<"\n";
        }
    }
}