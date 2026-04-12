#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
int mod;
const int ppp=131;

int tree[4*maxn],lazy[4*maxn];
int an_lazy[4*maxn];
int n,q;
int num[maxn];

int ls(int p){return p<<1;}
int rs(int p){return p<<1|1;}

void one_up(int p)
{tree[p]=((tree[ls(p)]%mod)+(tree[rs(p)]%mod))%mod;}


void down(int p,int len)
{
    if(an_lazy[p]!=1)
    {
        an_lazy[ls(p)]=((an_lazy[ls(p)])%mod*(an_lazy[p])%mod)%mod;
        an_lazy[rs(p)]=((an_lazy[rs(p)])%mod*(an_lazy[p])%mod)%mod;
        tree[ls(p)]=((tree[ls(p)]%mod)*(an_lazy[p])%mod)%mod;
        tree[rs(p)]=((tree[rs(p)]%mod)*(an_lazy[p])%mod)%mod;
        lazy[ls(p)]=(lazy[ls(p)]*an_lazy[p])%mod;
        lazy[rs(p)]=(lazy[rs(p)]*an_lazy[p])%mod;
        an_lazy[p]=1;
    }

    if(lazy[p])
    {
        lazy[ls(p)]+=lazy[p];lazy[rs(p)]+=lazy[p];
        tree[ls(p)]=((tree[ls(p)]%mod)+(lazy[p]*(len-(len>>1)))%mod)%mod;
        tree[rs(p)]=((tree[rs(p)]%mod)+(lazy[p]*(len>>1))%mod)%mod;
        lazy[p]=0;
    }

    
}

void build(int p,int l,int r)
{
    an_lazy[p]=1;
    if(l==r)
    {
        tree[p]=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    one_up(p);
}

void update(int p,int l,int r,int L,int R,int k)
{
    if(l>=L&&R>=r)
    {
        tree[p]=((tree[p]%mod)+(k*(r-l+1))%mod)%mod;
        lazy[p]+=k;
        return;
    }
    down(p,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
    update(ls(p),l,mid,L,R,k);
    if(R>mid)
    update(rs(p),mid+1,r,L,R,k);
    one_up(p);
}

void an_update(int p,int l,int r,int L,int R,int k)
{
    if(l>=L&&R>=r)
    {
        tree[p]=((tree[p]%mod)*k%mod)%mod;
        an_lazy[p]=((an_lazy[p]%mod)*k%mod)%mod;
        lazy[p]=(lazy[p]*k)%mod;
        return;
    }
    down(p,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
    an_update(ls(p),l,mid,L,R,k);
    if(R>mid)
    an_update(rs(p),mid+1,r,L,R,k);
    one_up(p);
}

int query(int p,int l,int r,int L,int R)
{
    if(l>=L&&R>=r)
    return tree[p];

    int ans=0;
    
    down(p,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid)
    ans=(ans%mod+query(ls(p),l,mid,L,R)%mod)%mod;
    if(R>mid)
    ans=(ans%mod+query(rs(p),mid+1,r,L,R)%mod)%mod;
    return ans;
}


signed main()
{
    cin>>n>>q>>mod;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    build(1,1,n);

    for(int i=1;i<=q;i++)
    {
        int op;cin>>op;
        if(op==2)
        {
            int x,y,k;cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }
        else if(op==1)
        {
            int x,y,k;cin>>x>>y>>k;
            an_update(1,1,n,x,y,k);
        }
        else
        {
            int x,y;cin>>x>>y;
            cout<<query(1,1,n,x,y)<<"\n";
        }
    }
}