#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=5000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,m;
int fa[maxn],idx;
vector<int>num;
unordered_map<int,int>unm;

struct node
{
    int l,r;string x;
};
vector<node>qwq;

int find(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}

void hb(int x,int y)
{
    if(x!=y)
    fa[find(x)]=find(y);
}

signed main()
{
    IOS;CT;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        string cur;cin>>cur;
        qwq.push_back({l,r,cur});
        num.push_back(l-1);num.push_back(r);
    }
    sort(num.begin(),num.end());
    for(auto x:num)
    {
        if(unm[x]==0)
        unm[x]=(++idx);
    }
    for(int i=1;i<=idx;i++)
    {fa[i]=i;fa[i+idx]=i+idx;}
    for(int i=1;i<=m;i++)
    {
        int x=qwq[i-1].l,y=qwq[i-1].r;
        string cur=qwq[i-1].x;
        int a=unm[x-1],b=unm[y];
        if(cur[0]=='e')
        {
            if(find(a)==find(b+idx))
            {
                cout<<i-1;
                return 0;
            }
            hb(a,b);
            hb(a+idx,b+idx);
        }
        else
        {
            if(find(a)==find(b))
            {
                cout<<i-1;
                return 0;
            }
            hb(a,b+idx);
            hb(a+idx,b);
        }
        
    }
    cout<<m;
}