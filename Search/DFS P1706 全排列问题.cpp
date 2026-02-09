#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010;
const ll INF=1e18+10;

int n;
bool ju[maxn];
int qwq[100];

void dfs(int step)
{
    if(step==n)
    {
        for(int i=1;i<=n;i++)
        printf("%5d",qwq[i]);
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ju[i])
        {
            ju[i]=1;
            qwq[step+1]=i;
            dfs(step+1);
            ju[i]=0; //回溯操作
        }
    }
}



signed main()
{
    cin>>n;
    dfs(0);
    
    return 0;
}