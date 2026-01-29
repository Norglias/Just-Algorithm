#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;
int n,m;
ll p[maxn],cnt=0;
void insert(ll x)
{
    for(int i=62;i>=0;i--)
    {
        if((x>>i)&1)
        {
            if(!p[i])
            {
                p[i]=x;cnt++;
                break;
            }
            x^=p[i];
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        char a;ll cur=0;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            if(a=='X')
            {
                ll aa=1LL<<j;
                cur+=aa;
            }
        }
        insert(cur);
    }
    ll ans=(1LL<<cnt)%2008;
    cout<<ans;
    
}