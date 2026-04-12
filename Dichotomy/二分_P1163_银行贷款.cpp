#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

double w0,w;
int m;

int solve(double x)
{
    double qwq=0;
    double asa=1;
    for(int i=1;i<=m;i++)
    {
        asa*=(1+x);
        qwq+=w/asa;
        // cout<<asa<<"\n";
    }
    if(qwq>w0)
    return 1;
    else if(qwq==w0)
    return 2;
    else
    return 0;
}

double binary(double l,double r)
{
    double mid;
    while(r-l>=0.0001)
    {
        mid=(l+r)/2.0;
        if(solve(mid)==1)
        l=mid;
        else if(solve(mid)==0)
        r=mid;
        else
        return mid;
    }
    return mid;
}


signed main()
{
    IOS;CT;
    cin>>w0>>w>>m;
    cout<<fixed<<setprecision(1)<<100.0*binary(0,5);
    // solve(0.029);
}