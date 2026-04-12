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

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int tree[4*maxn],lazy1[4*maxn],lazy2[4*maxn];
int num[maxn];

int ls(int p)
{return p<<1;}
int rs(int p)
{return p<<1|1;}


void up(int p)
{
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}

void down(int p)
{
    if(lazy1[p]!=-INF)
    {
        tree[ls(p)]=lazy1[p];lazy1[ls(p)]=lazy1[p];
        lazy2[ls(p)]=0;

        tree[rs(p)]=lazy1[p];lazy1[rs(p)]=lazy1[p];
        lazy2[rs(p)]=0;

        lazy1[p]=-INF;
    }
    if(lazy2[p]!=0)
    {
        tree[ls(p)]+=lazy2[p];tree[rs(p)]+=lazy2[p];
        lazy2[ls(p)]+=lazy2[p];lazy2[rs(p)]+=lazy2[p];
        lazy2[p]=0;
    }
}

void build(int p,int l,int r)
{
    lazy1[p]=-INF;lazy2[p]=0;
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

void update(int p,int l,int r,int L,int R,int k,int op)
{
    if(l>=L&&r<=R)
    {
        if(op==1)
        {
            lazy1[p]=k;
            tree[p]=k;
            lazy2[p]=0;
            return;
        }
        else
        {
            lazy2[p]+=k;
            tree[p]+=k;
            return;
        }
    }
    down(p);
    int mid=(l+r)>>1;
    if(L<=mid)update(ls(p),l,mid,L,R,k,op);
    if(R>mid)update(rs(p),mid+1,r,L,R,k,op);
    up(p);
}

int query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    return tree[p];
    down(p);
    int mid=(l+r)>>1;
    int res=-INF;
    if(L<=mid)
    res=max(res,query(ls(p),l,mid,L,R));
    if(R>mid)
    res=max(res,query(rs(p),mid+1,r,L,R));

    return res;
}

signed main()
{
    IOS;CT;
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    num[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,l,r;op=read(),l=read(),r=read();
        if(op==1||op==2)
        {
            int x=read();
            update(1,1,n,l,r,x,op);
        }
        else
        {
            int ans=query(1,1,n,l,r);
            cout<<ans<<"\n"; 
        }
    }
}