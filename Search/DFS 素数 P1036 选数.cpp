#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100000010;
const ll INF=1e18+10;

int n,k;
int num[30];
bool mark[30];
int ans;

bool ppp(int x)
{
    if(x==1)
    return 0;
    if(x==2)
    return 1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        return 0;
    }
    return 1;

}
void dfs(int pos,int sum,int step)
{
    
    if(pos-step-1>n-k)
    return;
    if(step==k)
    {
        if(ppp(sum))
        ans++;
        return;
    }
    for(int i=pos;i<=n;i++)
    {
        // if(mark[i])
        // continue;
        dfs(i+1,sum+num[i],step+1);
    }

}


signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>num[i];

    dfs(1,0,0);
    cout<<ans;
}