#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=200010;
const ll INF=1e9+10;

bool isprime[1000100];
int prime[maxn];
int cnt=0;

void solve(int r)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=0;

    for(int i=1;i<=r;i++)
    {
        if(isprime[i])
        prime[++cnt]=i;
        
        for(int j=1;j<=cnt&&i*prime[j]<=r;j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
            break;
        }
    }
}

int find(int l,int r)
{
    int cnt=0;
    for(int i=1;;i++)
    {
        if(prime[i]>=l&&prime[i]<=r)
        cnt++;

        if(prime[i]>r)
        break;
    }
    return cnt;
}

int main()
{
    int n,m;cin>>n>>m;
    solve(m);
    for(int i=1;i<=n;i++)
    {
        int l,r;cin>>l>>r;
        if(l>=1&&r<=m)
        cout<<find(l,r)<<"\n";
        else
        cout<<"Crossing the line"<<"\n";
    }

}