#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int n;
int num[maxn];

int gcd(int a,int b)
{
    while(b)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        num[i]=abs(x);
    }
    int awa=gcd(num[1],num[2]);
    for(int i=3;i<=n;i++)
    awa=gcd(awa,num[i]);
    
    cout<<awa;
}