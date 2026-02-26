#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n;
struct node
{
    char l,r;
};
node tree[maxn];

void solve(int p)
{
    char l=tree[p].l,r=tree[p].r;
    if(l=='*'&&r=='*')
    {
        return;
    }
    else if(l=='*')
    {
        cout<<r;
        solve((int)r);
    }
    else if(r=='*')
    {
        cout<<l;
        solve((int)l);
    }
    else
    {
        cout<<l;
        solve((int)l);
        cout<<r;
        solve((int)r);
    }
}



signed main()
{
    cin>>n;
    int fi=0;
    for(int i=1;i<=n;i++)
    {
        char c,l,r;cin>>c>>l>>r;
        if(i==1)
        fi=(int)c;
        int cur=(int)c;
        tree[cur]={l,r};
    }
    cout<<(char)fi;
    solve(fi);
}