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

int sum[4*maxn],lazy[4*maxn];

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
        lazy[ls(p)]+=lazy[p];lazy[rs(p)]+=lazy[p];
        sum[ls(p)]+=lazy[p]*(len-(len>>1));
        sum[rs(p)]+=lazy[p]*(len>>1);
        lazy[p]=0;
    }
}

void build(int p,int l,int r)
{
    lazy[p]=0;
    if(l==r)
    {
        sum[p]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);
}

void update(int p,int l1,int r1,int l2,int r2,int k)
{
    if(l2<=l1&&r2>=r1)
    {
        sum[p]+=k*(r1-l1+1);
        lazy[p]+=k;
        return;
    }
    down(p,r1-l1+1);
    int mid=(r1+l1)/2;
    if(l2<=mid)
    update(ls(p),l1,mid,l2,r2,k);
    if(r2>mid)
    update(rs(p),mid+1,r1,l2,r2,k);

    up(p);
}

int query(int p,int l,int r,int L,int R)
{
    if(l>=L&&r<=R)
    return sum[p];
    down(p,r-l+1);

    int mid=(r+l)/2;
    int ans=0;
    if(L<=mid)
    ans+=query(ls(p),l,mid,L,R);
    if(R>mid)
    ans+=query(rs(p),mid+1,r,L,R);
    return ans;
}

signed main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x,y,k;cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }
        else
        {
            int x,y;cin>>x>>y;
            cout<<query(1,1,n,x,y)<<"\n";
        }
    }
}