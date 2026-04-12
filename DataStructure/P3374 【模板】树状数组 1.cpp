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
int tree1[maxn];

int lowbit(int x)
{
    return x&(-x);
}

void add(int pos,int k)
{
    for(int i=pos;i<=n;i+=lowbit(i))
    tree1[i]+=k;
}

int q(int pos)
{
    int ans=0;
    for(int i=pos;i>0;i-=lowbit(i))
    {
        ans+=tree1[i];
    }
    return ans;
}
signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        add(i,x);
    }
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x,k;cin>>x>>k;
            add(x,k);
        }
        else
        {
            int l,r;cin>>l>>r;
            int ans=q(r)-q(l-1);
            cout<<ans<<"\n";
        }
    }
    
}
