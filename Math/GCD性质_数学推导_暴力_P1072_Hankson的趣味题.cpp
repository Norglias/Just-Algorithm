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

int gcd(int a,int b)
{
    while(b)
    {
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        int a0,a1,b0,b1;cin>>a0>>a1>>b0>>b1;
        int g1=a0/a1,g2=b1/b0;
        for(int x=1;x*x<=b1;x++)
        {
            if(b1%x==0)
            {
                int qwq=gcd(x/a1,g1),awa=gcd(g2,b1/x);
                if(x%a1==0&&qwq==1&&awa==1)
                ans++;
                
                int x2=b1/x;
                if(x==x2)
                continue;
                qwq=gcd(x2/a1,g1),awa=gcd(g2,b1/x2);
                if(x2%a1==0&&qwq==1&&awa==1)
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    
    
}

