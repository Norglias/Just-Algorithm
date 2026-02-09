#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;

int n;
string awa[30];
int qwq[100][100];
int used[25];
int l;

int judge(string a,string b)
{
    int ale=a.length(),ble=b.length();
    for(int i=1;i<min(ale,ble);i++)
    {
        string asub=a.substr(ale-i,i);
        string bsub=b.substr(0,i);
        if(asub==bsub)
        return i;
    }
    return 0;
}

void dfs(int u,int length)
{
    l=max(l,length);
    for(int v=1;v<=n;v++)
    {
        if(used[v]<2&&qwq[u][v]>0)
        {
            used[v]++;
            int ble=awa[v].length();
            dfs(v,length+ble-qwq[u][v]);
            used[v]--;
        }
    }
}



signed main()
{   
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>awa[i];

    char tar;cin>>tar;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            qwq[i][j]=judge(awa[i],awa[j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(awa[i][0]==tar)
        {
            used[i]++;
            int lll=awa[i].length();
            dfs(i,lll);
            used[i]--;
        }
    }
    cout<<l;
}