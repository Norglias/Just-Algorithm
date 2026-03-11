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

int n,m;
int num[maxn],ti[maxn];
int rs[maxn],re[maxn],pos;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    queue<int>q;
    int ans=-1,start=1,count=0;
    for(int i=1;i<=n;i++)
    {
        q.push(num[i]);
        if(ti[num[i]]==0)
        count++;
        ti[num[i]]++;
        if(count==m)
        {
            while(1)
            {
                if(count<m)
                break;
                
                int top=q.front();
                q.pop();
                
                ti[top]--;
                if(ti[top]==0)
                {
                    count--;
                }
                rs[++pos]=start,re[pos]=i;
                start++;
            }
        }
    }

    int ansx=0,ansy=0,minn=INF;
    for(int i=1;i<=pos;i++)
    {
        // cout<<re[i]<<" "<<rs[i]<<"\n";
        if(re[i]-rs[i]<minn)
        {
            minn=re[i]-rs[i];
            ansx=rs[i],ansy=re[i];
        }
    }
    cout<<ansx<<" "<<ansy;
    
}

