#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

string zhong,hou;

void solve(string z,string h)
{
    if(z.empty()||h.empty())
    return;
    int l=h.length();
    char root=h[l-1];
    int pos=z.find(root);
    string le=z.substr(0,pos);
    string ri=z.substr(pos+1);
    int lll=le.length();
    string hle=h.substr(0,lll);
    string hri=h.substr(lll,l-lll-1);

    cout<<root;
    solve(le,hle);
    solve(ri,hri);
}



signed main()
{   
    cin>>zhong>>hou;
    solve(zhong,hou);

}