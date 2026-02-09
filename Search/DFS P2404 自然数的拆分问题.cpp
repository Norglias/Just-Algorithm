#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1010;
const ll INF=1e18+10;

int n;
int way[maxn];
int cnt=0;

void dfs(int x,int index,int num)
{
    if(x==n)
    return;
    if(num==n)
    {
        for(int i=1;i<index;i++)
        {
            if(i==1)
            cout<<way[i];
            else
            cout<<'+'<<way[i];
        }
        cout<<"\n";
        cnt++;
        return;
    }
    for(int i=x;i<=n-num;i++)
    {
        way[index]=i;
        dfs(i,index+1,num+i);
    }
}



signed main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>n;
    dfs(1,1,0);
}