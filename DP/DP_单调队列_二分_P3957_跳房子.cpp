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

int n,d,k;
struct node
{int dis,w;};
node qwq[maxn];
int dp[maxn],qu[maxn];

bool check(int x)
{
    int curl=max(0LL,d-x),curr=d+x;
    if(curl==0)
    curl=1;

    for(int i=1;i<=n;i++)
    {
        dp[i]=-INF;
    }
    dp[0]=0;
    int p=0,head=1,tail=0;
    for(int i=1;i<=n;i++)
    {
        int pos=qwq[i].dis;
        while(p<i&&pos-qwq[p].dis>=curl)
        {
            while(head<=tail&&dp[p]>=dp[qu[tail]])
            tail--;
            qu[++tail]=p;
            p++;
        }
        while(head<=tail&&pos-qwq[qu[head]].dis>curr)
        head++;
        if(head<=tail)
        dp[i]=dp[qu[head]]+qwq[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>=k)
        return 1;
    }
    return 0;
}


int binary(int l,int r)
{
    int ans=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        l=mid+1;
    }
    return ans;
}


signed main()
{
    IOS;CT;
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        qwq[i].dis=a;qwq[i].w=b;
    }
    cout<<binary(0,10000000);

}