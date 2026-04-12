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

int n,l,k;
bool qwq[maxn];
vector<int>cut;
int ans=INF;

bool check(int x)
{
    int total=0;
    if(x==0)
    {
        return 0;
    }
    for(int i=1;i<cut.size();i++)
    {
        int diff=cut[i]-cut[i-1];
        if(diff%x==0)
        total+=diff/x-1;
        else
        total+=diff/x;
    }
    if(total<=k)
    return 1;
    else
    return 0;
}


int binary(int le,int ri)
{
    int ans=0;
    while(le<=ri)
    {
        int mid=(le+ri)>>1;
        if(check(mid))
        {
            ans=mid;
            ri=mid-1;
        }
        else
        le=mid+1;
    }
    return ans;
}


signed main()
{
    IOS;CT;
    cin>>l>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        cut.push_back(x);
        qwq[x]=1;
    }
    cout<<binary(0,l);
}