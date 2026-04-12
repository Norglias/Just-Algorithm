#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n;
int qwq[500][500];
int sum[500][500];


signed main()
{
    IOS;CT;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>qwq[i][j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=qwq[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int ans=-INF;
    for(int k=1;k<=n;k++)
    {
        for(int k1=1;k1<=n;k1++)
        {
            for(int i=k;i<=n;i++)
            {
                for(int j=k1;j<=n;j++)
                {
                    int tar=sum[i][j]-sum[i-k][j]-sum[i][j-k1]+sum[i-k][j-k1];
                    // cout<<tar<<"\n";
                    ans=max(ans,tar);
                }
            }
        }
    }

    cout<<ans;
}