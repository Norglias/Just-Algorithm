#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,k;
int le[maxn];

bool check(int x)
{
    int tar=0;
    for(int i=1;i<=n;i++)
    {
        tar+=le[i]/x;
    }
    if(tar>=k)
    return 1;
    else
    return 0;
}


int binary(int l,int r)
{
    int ans=-INF;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
        r=mid-1;
    }
    return ans;
}


signed main()
{
    IOS;CT;
    cin>>n>>k;
    int minl=-INF;
    for(int i=1;i<=n;i++)
    {
        cin>>le[i];
        minl=max(minl,le[i]);
    }
    int ans=binary(1,minl);
    if(ans==-INF)
    ans=0;
    cout<<ans;
}