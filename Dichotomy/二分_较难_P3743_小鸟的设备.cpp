#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int n,p;
struct node
{
    int a,b;
    double t;
};
node qwq[maxn];



bool check(double x)
{
    double cur=0;
    for(int i=1;i<=n;i++)
    {
        if(qwq[i].a*x<=qwq[i].b)
        continue;
        if(qwq[i].a*x>qwq[i].b)
        {
            cur+=qwq[i].a*x-qwq[i].b;
        }
    }
    if(cur>p*x)
    return 0;
    return 1;
}

double binary(double l,double r)
{
    double ans=-1;
    while((r-l)>0.000001)
    {
        double mid=(l+r)/2.0;
        if(check(mid))
        {
            ans=max(ans,mid);
            l=mid;
        }
        else
        r=mid;
    }
    return ans;
}


signed main()
{
    IOS;CT;
    cin>>n>>p;
    double maxt=(double)-INF;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        qwq[i].a=x;qwq[i].b=y;
        qwq[i].t=(double)y/(double)x;
        maxt=max(maxt,qwq[i].t);
    }
    bool check=0;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=qwq[i].a;
    }
    if(p>=sum)
    check=1;
    if(check)
    cout<<"-1";
    else
    cout<<fixed<<setprecision(10)<<binary(0,1e11);
}