#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=2000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,k;
int tree[4*maxn];
int num[maxn];

int ls(int p)
{return p<<1;}
int rs(int p)
{return (p<<1)|1;}

void up(int p)
{tree[p]=max(tree[ls(p)],tree[rs(p)]);}

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

int query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    return tree[p];

    int mid=(l+r)>>1;
    int ans=-INF;
    if(L<=mid)
    ans=max(ans,query(ls(p),l,mid,L,R));
    if(R>mid)
    ans=max(ans,query(rs(p),mid+1,r,L,R));

    return ans;
}

signed main()
{
    IOS;CT;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>num[i];

    build(1,1,n);
    int l=1;
    for(int i=k;i<=n;i++)
    cout<<query(1,1,n,l++,i)<<"\n";
    
}