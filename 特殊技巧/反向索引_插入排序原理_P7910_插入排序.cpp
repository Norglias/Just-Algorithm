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
int num[maxn];
int pos[maxn];
struct s
{
    int n,pos;
};vector<s>qwq;

bool cmmp(s a,s b)
{
    if(a.n!=b.n)
    return a.n<b.n;
    return a.pos<b.pos;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        qwq.push_back({num[i],i});
    }
    sort(qwq.begin(),qwq.end(),cmmp);
    for(int i=1;i<=n;i++)
    pos[qwq[i-1].pos]=i;
    
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x,v;cin>>x>>v;
            int p=pos[x],curp=p-1;
            qwq[p-1].n=v;
            while(curp<n-1&&cmmp(qwq[curp+1],qwq[curp]))
            {
                pos[qwq[curp].pos]++;
                pos[qwq[curp+1].pos]--;
                swap(qwq[curp],qwq[curp+1]);
                curp++;
            }
            while(curp>0&&cmmp(qwq[curp],qwq[curp-1]))
            {
                pos[qwq[curp].pos]--;
                pos[qwq[curp-1].pos]++;
                swap(qwq[curp],qwq[curp-1]);
                curp--;
            }
        }
        else if(op==2)
        {
            int tar;cin>>tar;
            cout<<pos[tar]<<"\n";
        }
    }
}

