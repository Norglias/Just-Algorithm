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

int m,n;
int school[maxn];
int a[maxn];




signed main()
{
    IOS;CT;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>school[i];
    }
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(school+1,school+m+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int cur=a[i];
        auto qwq=upper_bound(school+1,school+m+1,cur);
        int nnn=*qwq;
        if(nnn!=school[1])
        {
            int ass=*(qwq-1);
            ans+=min(abs(ass-cur),abs(nnn-cur));
            
        }
        else
        ans+=abs(nnn-cur);
    }
    cout<<ans;
}