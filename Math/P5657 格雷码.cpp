#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR; 

int num[maxn],cnt=0;
int n,k;

signed main()
{
    cin>>n>>k;

    int ans=k^(k>>1);
    
    while(ans)
    {
        if(ans&1)
        num[++cnt]=1;
        else
        ++cnt;
        ans>>=1;
    }
    for(int i=n;i>=1;i--)
    cout<<num[i];
}