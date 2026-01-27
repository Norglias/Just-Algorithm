#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const int INF=1e9;
const ull ppp=131;

vector<pair<int,int>>graph[maxn];
int tow[maxn];int time1[maxn];int t2[maxn];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num,t;cin>>num>>t;
        int cur;
        t2[i]=t;
        while (1)
        {
            cin>>cur;
            if(cur==0)
            break;
            graph[cur].push_back({num,t});
            tow[num]++;
        }
    }
    queue<int>que;
    for(int i=1;i<=n;i++)
    {
        if(tow[i]==0)
        {
            que.push(i);
            time1[i]=t2[i];
        }
        else
        time1[i]=t2[i];
    }
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        for(auto &x:graph[u])
        {
            int v=x.first;int w=x.second;
            
            time1[v]=max(time1[v],time1[u]+w);
            
            tow[v]--;
            if(tow[v]==0)
            que.push(v);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    ans=max(ans,time1[i]);
    cout<<ans;

}