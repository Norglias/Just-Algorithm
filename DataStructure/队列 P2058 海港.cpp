#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n,ans;
int check[maxn];
int t;

signed main()
{
    cin>>n;
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>t>>k;
        for(int j=1;j<=k;j++)
        {
            int x;cin>>x;
            q.push({t,x});
            check[x]++;
            if(check[x]==1)ans++;
        }
        while(!q.empty())
        {
            if(q.back().first-q.front().first>=86400)
            {
                int curn=q.front().second;
                check[curn]--;
                if(check[curn]==0)
                ans--;
                q.pop();
            }
            else
            break;
        }
        cout<<ans<<"\n";
    }
    
}