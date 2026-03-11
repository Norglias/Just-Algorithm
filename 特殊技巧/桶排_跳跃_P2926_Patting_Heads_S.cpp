#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ll mod=1e9+7;
const int ppp=131;

int n;
int num[maxn];
int ans[maxn];
int m[maxn];
int maxx;
void solve(int x)
{
    for(int i=1;i<=1e6;i++)
    {
        if(m[i]>0)
        {
            for(int j=1;j*i<=1e6;j++)
            {
                ans[j*i]+=m[i];
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        m[num[i]]++;
        maxx=max(maxx,num[i]);
    }
    solve(n);
    for(int i=1;i<=n;i++)
    cout<<ans[num[i]]-1<<"\n";
    

}

