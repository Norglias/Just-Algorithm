#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=3000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int t;
int trie[maxn][70];
int cnt[maxn];
int idx;

int cha(char a)
{
    if(a>='A'&&a<='Z')
    return a-'A';
    else if(a>='a'&&a<='z')
    return a-'a'+26;
    else
    return a-'0'+52;
}


void insert(string s)
{
    int u=0;
    for(auto c:s)
    {
        int v=cha(c);
        if(trie[u][v]==0)
        trie[u][v]=++idx;
        u=trie[u][v];
        cnt[u]++;
    }
    
}

int query(string s)
{
    int u=0;
    for(auto c:s)
    {
        int v=cha(c);
        if(trie[u][v]==0)
        return 0;
        u=trie[u][v];
    }
    return cnt[u];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int ans=0;
        int n,q;cin>>n>>q;
        for(int j=0;j<=idx;j++)
            for(int k=0;k<=61;k++)
            trie[j][k]=0;
        for(int j=0;j<=idx;j++)
        cnt[j]=0;
        idx=0;
        for(int j=1;j<=n;j++)
        {
            string x;cin>>x;
            insert(x);
        }
        for(int j=1;j<=q;j++)
        {
            string x;cin>>x;
            int qwq=query(x);
            cout<<qwq<<"\n";
        }
    }
}