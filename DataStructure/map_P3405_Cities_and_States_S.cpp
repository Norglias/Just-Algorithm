#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=212370440130137957ll;
const int ppp=131;
int n;
map<int,int>m[maxn];

signed main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        string a,b;cin>>a>>b;
        int A=a[0]*ppp+a[1];
        int B=b[0]*ppp+b[1];
        
        if(A!=B)
        ans+=m[B][A];
        m[A][B]++;
    }
    cout<<ans;
}