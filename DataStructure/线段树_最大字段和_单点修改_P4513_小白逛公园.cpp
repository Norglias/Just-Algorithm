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
const int mod=1e9+7;
const int ppp=131;

struct node
{
    int sum,max,maxl,maxr;
};
node tree[4*maxn];
int num[maxn];
int n;

int ls(int p)
{return p<<1;}
int rs(int p)
{return p<<1|1;}

node combine(node a,node b)
{
    node ans;
    ans.sum=a.sum+b.sum;
    ans.maxl=max(a.maxl,a.sum+b.maxl);
    ans.maxr=max(b.maxr,b.sum+a.maxr);
    ans.max=max({a.max,b.max,a.maxr+b.maxl});
    return ans;
}


void up(int p)
{
    tree[p]=combine(tree[ls(p)],tree[rs(p)]);
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        tree[p].max=tree[p].sum=tree[p].maxl=tree[p].maxr=num[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);
}


void update(int p,int l,int r,int tar,int k)
{
    if(l==r)
    {
        tree[p].max=tree[p].sum=tree[p].maxl=tree[p].maxr=k;
        return;
    }
    int mid=(l+r)>>1;
    if(tar<=mid)
    update(ls(p),l,mid,tar,k);
    else
    update(rs(p),mid+1,r,tar,k);
    up(p);
}

node query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    return tree[p];

    int ans=-INF;
    int mid=(l+r)>>1;
    if(R<=mid)
    return query(ls(p),l,mid,L,R);
    if(L>mid)
    return query(rs(p),mid+1,r,L,R);

    node le=query(ls(p),l,mid,L,R);
    node ri=query(rs(p),mid+1,r,L,R);
    return combine(le,ri);
}

signed main()
{
    IOS;CT;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,x,y;cin>>op>>x>>y;
        if(op==1)
        {
            if(x>y)
            swap(x,y);
            cout<<query(1,1,n,x,y).max<<"\n";
        }
        else
        update(1,1,n,x,y);
    }
}