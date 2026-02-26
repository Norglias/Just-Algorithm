#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

signed main()
{
    string qian,hou;cin>>qian>>hou;
    int le=qian.length();
    int ans=0;
    for(int i=0;i<le-1;i++)
    {
        string cur=qian.substr(i,2);
        reverse(cur.begin(),cur.end());
        if(hou.find(cur)!=string::npos)
        ans++;
    }
    cout<<(1LL<<ans);
}