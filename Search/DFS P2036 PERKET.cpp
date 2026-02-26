#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int n,ans=INF;
vector<pair<int,int>>qwq;

void dfs(int pos,int s,int b)
{
    if(pos>=n)
    {
        if(s==1&&b==0)
        return;
        int awa=abs(s-b);
        ans=min(awa,ans);
        return;
    }
    dfs(pos+1,s*qwq[pos].first,b+qwq[pos].second);
    dfs(pos+1,s,b);
}

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int s,b;cin>>s>>b;
        qwq.push_back({s,b});
    }

    dfs(0,1,0);
    cout<<ans;
}