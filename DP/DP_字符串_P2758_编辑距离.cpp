#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
const ll INF1=1e19+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;


string a,b;
int dp[5000][5000];

signed main()
{
    IOS;CT;
    cin>>a>>b;
    

    for(int i=0;i<=a.length();i++)
    dp[i][0]=i;
    for(int j=0;j<=b.length();j++)
    dp[0][j]=j;

    for(int i=1;i<=a.length();i++)
    {
        for(int j=1;j<=b.length();j++)
        {
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
        }
    }
    cout<<dp[a.length()][b.length()];
}