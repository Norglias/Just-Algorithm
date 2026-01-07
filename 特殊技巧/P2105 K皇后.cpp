#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

bool hang[20020],lie[MAXN],diag[maxn],diag0[maxn];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int x,y;
    for(int i=1;i<=k;i++)
    {
        cin>>x>>y;
        hang[x]=true;lie[y]=true;diag[x+y]=true;diag0[x-y+MAXN]=true;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(hang[i]||lie[j]||diag[i+j]||diag0[i-j+MAXN])
            continue;
            cnt++;
        }
    }
    cout<<cnt;
}