#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=80112002;
const int ppp=131;

int n;
int in[maxn],time1[maxn],dp[maxn];
vector<int>work[maxn];


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        int pos,p;cin>>pos>>time1[i];
        while(1)
        {
            cin>>p;
            if(p==0)
            break;
            in[pos]++;
            work[p].push_back(pos);
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            dp[i]=time1[i];
            q.push(i);
        }
    }
    int ans=0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(auto x:work[top])
        {
            dp[x]=max(dp[x],dp[top]+time1[x]);
            in[x]--;
            if(in[x]==0)
            q.push(x);
        }
    }
    
    for(int i=1;i<=n;i++)
    ans=max(ans,dp[i]);
    cout<<ans;

}

