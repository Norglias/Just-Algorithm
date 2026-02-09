#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int n,sum;
int num[maxn];
int awa[maxn];

signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];sum+=num[i];
    }
    int avg=sum/n;
    for(int i=1;i<=n;i++)
    awa[i]=awa[i-1]+num[i]-avg;
    
    sort(awa+1,awa+n+1);

    int mid=awa[(n+1)/2]; //计算中位数
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=abs(awa[i]-mid);
    }
    cout<<ans;
}