#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int t;
int a[maxn],b[maxn];

signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;cin>>n;
        for(int j=1;j<=n;j++)
        cin>>a[j];
        for(int j=1;j<=n;j++)
        cin>>b[j];

        stack<int>s;
        int pos=1;
        for(int j=1;j<=n;j++)
        {
            s.push(a[j]);
            while((s.top())==b[pos])
            {
                s.pop();
                pos++;
                if(s.empty())
                break;
            }
        }
        if(s.empty())
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
}