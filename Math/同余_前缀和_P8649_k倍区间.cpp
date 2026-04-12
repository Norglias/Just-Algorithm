#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e6+7;
const int ppp=131;

int n,k;
int num[maxn];
int sum[maxn];
int cnt[maxn];

signed main()
{
    IOS;CT;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        sum[i]=sum[i-1]+num[i];
    }

    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans+=cnt[sum[i]%k]++;
    }
    cout<<ans;

}