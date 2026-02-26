#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

void dfs(string zhong,string qian)
{
    if(zhong.empty()||qian.empty())
    return;

    char root=qian[0];
    int pos=zhong.find(root);
    string le=zhong.substr(0,pos);
    string ri=zhong.substr(pos+1);
    int l=le.length();
    string ple=qian.substr(1,l);
    string pri=qian.substr(l+1);

    dfs(le,ple);
    dfs(ri,pri);

    cout<<root;
}


signed main()
{
    string zhong,qian;cin>>zhong>>qian;
    dfs(zhong,qian);
}