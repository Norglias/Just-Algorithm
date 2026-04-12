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
int achas=0;
int num[maxn];
int sum[maxn];

int solve(int x)
{
    int cur=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(cur+num[i]>x)
        {
            cur=0;
            cnt++;
        }
        cur+=num[i];
    }
    if(cnt>m)
    return -1;
    if(cnt<=m)
    return 1;
}

int binary(int l,int r)
{
    int ans=r;

    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(solve(mid)==1)
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else if(solve(mid)==-1)
        l=mid+1;
    }
    return ans;
}

signed main()
{
    IOS;CT;
    int l=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        achas+=num[i];

        l=max(l,num[i]);
    }
    int re=binary(l,achas);
    cout<<re;
    
    // cout<<solve(3);
}