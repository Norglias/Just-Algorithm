#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n;
bool check;
bool dp[1000][1000];
int cnt;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int r=1;r<=i;r++)
        {
            for(int j=0;j<=(i-r)*(i-r-1)/2;j++)
            if(dp[i-r][j])
            dp[i][j+r*(i-r)]=1;
        }
    }
    int cnt=0;
    for(int i=0;i<=1000;i++)
    if(dp[n][i])
    cnt++;
    cout<<cnt;
    

}

