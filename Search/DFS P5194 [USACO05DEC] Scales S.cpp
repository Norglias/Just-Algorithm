#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010;

int n,c,pos;
int w[maxn],num[maxn],ans;

void dfs(int index,int x)
{
    if(x>c)
    return;

    if(num[index-1]+x<=c)
    {
        ans=max(ans,num[index-1]+x);
        return;
    }
    ans=max(ans,x);
    for(int i=1;i<index;i++)
    dfs(i,x+w[i]);
}


signed main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        if(w[i]<=c)
        num[i]=num[i-1]+w[i];
    }
    dfs(n+1,0);
    cout<<ans;
}