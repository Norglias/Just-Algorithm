#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=80112002;
const int ppp=131;

int t,k;
int f[2010][2010],ans[2020][2020],cnt[2020][2020];

void solve()
{
    f[0][0]=f[1][0]=f[1][1]=1;
    for(int i=2;i<=2000;i++)
    {
        f[i][0]=1;
        for(int j=1;j<=2000;j++)
        {
            if(i>=j)
            {
                f[i][j]=(f[i-1][j]+f[i-1][j-1])%k;
                if(f[i][j]==0)
                cnt[i][j]=1;
            }
            ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+cnt[i][j];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t>>k;
    solve();
    for(int i=1;i<=t;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<ans[x][y]<<"\n";
    }

}

