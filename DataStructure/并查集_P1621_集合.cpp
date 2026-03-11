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

int a,b,ans,p;
int prime[maxn],fa[maxn],cnt,sum;
bool notprime[maxn];
bool mark[maxn];

int find(int x)
{
    if(fa[x]==x)
    return x;
    else
    return fa[x]=find(fa[x]);
}


void init(int n)
{
    notprime[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!notprime[i])
        prime[++cnt]=i;

        for(int j=1;j<=cnt&&i*prime[j]<=n;j++)
        {
            notprime[i*prime[j]]=1;

            if(i%prime[j]==0)
            break;
        }
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>p;
    for(int i=1;i<=b;i++)
    fa[i]=i;

    init(b);
    for(int i=1;i<=cnt;i++)
    {
        int ppp=prime[i];
        if(prime[i]<p)
        continue;
        for(int j=2;j*prime[i]<=b;j++)
        {
            if(prime[i]*j<a)
            continue;

            fa[find(prime[i])]=find(prime[i]*j);
        }
    }
    for(int i=a;i<=b;i++)
    if(fa[i]==i)
    sum++;

    cout<<sum;
}