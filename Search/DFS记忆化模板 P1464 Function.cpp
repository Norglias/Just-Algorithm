#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int a,b,c;
int f[30][30][30];


int dfs(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
    return 1;

    if(a>20||b>20||c>20)
    return dfs(20,20,20);
    
    else if(a<b&&b<c)
    {
        if(f[a][b][c-1]==0)
        f[a][b][c-1]=dfs(a,b,c-1);
        if(f[a][b-1][c-1]==0)
        f[a][b-1][c-1]=dfs(a,b-1,c-1);
        if(f[a][b-1][c]==0)
        f[a][b-1][c]=dfs(a,b-1,c);
        return f[a][b][c-1]+f[a][b-1][c-1]-f[a][b-1][c];
    }
    else
    {
        if(f[a-1][b][c]==0)
        f[a-1][b][c]=dfs(a-1,b,c);
        if(f[a-1][b-1][c]==0)
        f[a-1][b-1][c]=dfs(a-1,b-1,c);
        if(f[a-1][b][c-1]==0)
        f[a-1][b][c-1]=dfs(a-1,b,c-1);
        if(f[a-1][b-1][c-1]==0)
        f[a-1][b-1][c-1]=dfs(a-1,b-1,c-1);
        return f[a-1][b][c]+f[a-1][b-1][c]+f[a-1][b][c-1]-f[a-1][b-1][c-1];
    }
}

signed main()
{
    while(cin>>a>>b>>c)
    {
        if(a==-1&&b==-1&&c==-1)
        break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,dfs(a,b,c));
    }
}