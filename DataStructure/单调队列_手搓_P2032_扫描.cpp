#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=2000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,k;
int num[maxn];
int q[maxn];
int h=1,t=0;

signed main()
{
    IOS;CT;
    cin>>n>>k;
    int x=k;
    for(int i=1;i<=n;i++)
    cin>>num[i];
    
    for(int i=1;i<=n;i++)
    {
        while(h<=t&&q[h]<=i-k)
        h++;
        while(h<=t&&num[q[t]]<=num[i])
        t--;
        q[++t]=i;
        if(i>=k)
        cout<<num[q[h]]<<"\n";
    }
    
    
}