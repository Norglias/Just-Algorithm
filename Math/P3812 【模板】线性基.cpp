#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;

struct LiBasis
{
    ll p[65]; //存储线性基
    LiBasis(){
        memset(p,0,sizeof(p));
    }
    void insert(ll x)
    {
        for(int i=62;i>=0;i--)
        {
            if((x>>i)&1)
            {
                if(!p[i])
                {
                    p[i]=x;
                    break;
                }
                x^=p[i];
            }
        }
    }
    bool check(ll k)
    {
        for(int i=62;i>=0;i--)
        {
            if((k>>i)&1)
            {
                if(!p[i])
                return 0;
                k^=p[i];
            }
        }
        return 1;
    }
    ll qmax()
    {
        ll ans=0;
        for(int i=62;i>=0;i--)
        {
            if((ans^p[i])>ans)
            ans=ans^p[i];
        }
        return ans;
    }
};

int main()
{
    int n;cin>>n;
    LiBasis ppp;
    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        ppp.insert(x);
    }
    cout<<ppp.qmax();
}