#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010;
const ll INF=1e18+10;

int s[10];
int num[10][100];
int l,r,ans;

void dfs(int in,int x)
{
    if(x>s[in])
    {
        ans=min(ans,max(l,r));
        return;
    }

    l+=num[in][x];
    dfs(in,x+1);
    l-=num[in][x];
    r+=num[in][x];
    dfs(in,x+1);
    r-=num[in][x];
}



signed main()
{
    for(int i=1;i<=4;i++)
    cin>>s[i];

    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=s[i];j++)
        cin>>num[i][j];
    }
    int total=0;
    for(int i=1;i<=4;i++)
    {
        ans=INF;
        dfs(i,1);
        total+=ans;
    }
    cout<<total<<endl;
    return 0;
    
}