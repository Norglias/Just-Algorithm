#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

int n;
int fa[maxn];
double dis[maxn];
bool root[maxn];
vector<pair<double,double> >city;


double distance(double x1,double y1,double x2,double y2)
{
    double p1=(x1-x2)*(x1-x2);
    double p2=(y1-y2)*(y1-y2);
    return sqrt(p1+p2);
}


double prim()
{
    dis[1]=0.0;
    int cur;
    double minn;
    double ans=0.0;
    for(int i=1;i<=n;i++)
    {
        cur=1;minn=1e14*1.0;
        for(int j=1;j<=n;j++)
        {
            if(!root[j]&&dis[j]<minn)
            {
                cur=j;minn=dis[j];
            }
        }
        root[cur]=true;
        ans+=dis[cur];
        for(int j=1;j<=n;j++)
        {
            dis[j]=min(dis[j],distance(city[j].first,city[j].second,city[cur].first,city[cur].second));
        }
    }
    return ans;
}


int main()
{
    cin>>n;
    city.push_back({0,0});
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        city.push_back({x,y});
        dis[i]=1e15+1.0;
    }
    printf("%.2lf",prim());
    return 0;
}