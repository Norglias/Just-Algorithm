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
    vector<int>next(le,0);

    for(int i=1,j=0;i<le;i++)
    {
        while(p[i]!=p[j]&&j>0)
        j=next[j-1];
        if(p[i]==p[j])
        j++;
        next[i]=j;
    }
    return next;
}

int find(int cur,vector<int>&nxt)
{
    if(nxt[cur]!=0&&nxt[nxt[cur]-1]!=0)
    nxt[cur]=find(nxt[cur]-1,nxt);
    return nxt[cur];
}

signed main()
{
    cin>>n;
    string qwq;
    cin>>qwq;
    vector<int>ans=build(qwq);
    int cnt=0;
    for(auto x:qwq)
    cout<<x<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        int awa=find(i,ans);
        for(auto x:ans)
        cout<<x<<" ";
        cout<<"\n";
        if(awa==0)
        continue;
        cnt+=i+1-awa;
    }
    cout<<cnt;
    
}