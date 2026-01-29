#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;

int n,x;

int num[maxn],cnt=0;


int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        int q;cin>>q;
        if(q>x)
        num[++cnt]=q;
    }
    ll ans=0;
    for(int i=1;i<=cnt;i++)
    {
        int y=0;
        for(int j=30;j>=0;j--)
        {
            if((num[i]>>j)&1)
            {
                if((1<<j)+y<=x)
                y=(1<<j)+y;
            }   
        }
        ans+=num[i]^y;
    }
    cout<<ans;
}