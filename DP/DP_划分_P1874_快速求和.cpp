#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e18+10;
const ll INF1=1e19+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;

int n,m;
int num[600][600];
string s;
int dp[50][200010];


signed main()
{
    IOS;CT;
    cin>>s;
    cin>>n;
    for(int i=1;i<=s.length();i++)
    {
        for(int j=i;j<=s.length();j++)
        {
            num[i][j]=INF;
        }
    }
    //最恶心的处理越界部分,比想DP还恶心
    for(int i=1;i<=s.length();i++)
    {
        int val=0;
        for(int j=i;j<=s.length();j++)
        {
            val=val*10+(s[j-1]-'0');
            if(val>n)
            break;
            else
            num[i][j]=val;
        }
    }
    for(int i=1;i<=s.length();i++)
        for(int j=0;j<=n;j++)
        dp[i][j]=INF;

    for(int i=1;i<=s.length();i++)
    {
        if(num[1][i]<=n)
        dp[i][num[1][i]]=0;
        for(int k=1;k<i;k++)
        {
            int curn=num[k+1][i];
            for(int j=n;j>=curn;j--)
            dp[i][j]=min(dp[i][j],dp[k][j-curn]+1);
        }
    }
    if(dp[s.length()][n]!=INF)
    cout<<dp[s.length()][n];
    else
    cout<<"-1";

}