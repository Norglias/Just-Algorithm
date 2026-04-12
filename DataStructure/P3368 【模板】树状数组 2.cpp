#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,m;
int tree[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void add(int pos,int k)
{
    for(int i=pos;i<=n;i+=lowbit(i))
    tree[i]+=k;
}

int query(int pos)
{
    int ans=0;
    for(int i=pos;i>0;i-=lowbit(i))
    ans+=tree[i];
    return ans;
}

signed main()
{
    IOS;CT;
    cin>>n>>m;
    int pr=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        add(i,x-pr);
        pr=x;
    }
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int l,r,k;cin>>l>>r>>k;
            add(l,k);
            add(r+1,-k);
        }
        else if(op==2)
        {
            int x;cin>>x;
            cout<<query(x)<<"\n";
        }
    }
    
}
