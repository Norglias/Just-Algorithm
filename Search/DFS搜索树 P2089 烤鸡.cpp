#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100000010;
const ll INF=1e18+10;

int n;
int ans[15];
int qwq[100000][15];
int cnt;
void dfs(int cur,int sum,int step)
{
    if(sum>n)
    return;
    // cout<<cur<<" "<<sum<<" "<<step<<"\n";
    ans[step]=cur;
    if(step==10)
    {
        if(sum!=n)
        return;
        else
        {
            cnt++;
            for(int i=1;i<=10;i++)
            qwq[cnt][i]=ans[i];
            return;
        }
    }
    for(int i=1;i<=3;i++)
    {
        dfs(i,sum+i,step+1);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>n;
    if(n>30)
    {
        cout<<0;
        return 0;
    }
    dfs(0,0,0);
    cout<<cnt<<"\n";
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=10;j++)
        cout<<qwq[i][j]<<" ";
        cout<<"\n";
    }
}