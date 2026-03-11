#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=1000000ll;
const int ppp=131;

unordered_map<string,string>fa;
string father,son;

string find(string x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        string qwq;cin>>qwq;
        
        if(qwq[0]=='#')
        {
            father=qwq.substr(1);
            if(fa[father]=="")
            fa[father]=father;
            else
            fa[father]=find(father);
        }
        else if(qwq[0]=='+')
        {
            son=qwq.substr(1);
            fa[son]=find(father);
        }
        else if(qwq[0]=='?')
        {
            son=qwq.substr(1);
            cout<<son<<" "<<find(son)<<"\n";
        }
        else if(qwq[0]=='$')
        break;
    }
}

