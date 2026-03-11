#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n;

vector<int>build(string p)
{
    int le=p.length();
    vector<int>nxt(le,0);

    for(int i=1,j=0;i<le;i++)
    {
        while(j>0&&p[i]!=p[j])
        j=nxt[j-1];
        if(p[i]==p[j])
        j++;
        nxt[i]=j;
    }
    return nxt;
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string s;
    cin>>s;
    vector<int>ans=build(s);
    int qwq=-INF;
    for(auto x:ans)
    cout<<x<<" ";
    cout<<ans[n-1]<<" "<<n-ans[n-1];
}

