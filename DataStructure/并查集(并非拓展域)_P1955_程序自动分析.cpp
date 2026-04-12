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

int t,n,m;
int fa[400100];

struct node
{
    int l,r,e;
};


int find(int x)
{
    if(fa[x]==x)
    return x;
    else 
    return fa[x]=find(fa[x]);
}

signed main()
{
    IOS;CT;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,idx=0;cin>>n;
        
        memset(fa,0,sizeof(fa));

        unordered_map<int,int>unm;
        vector<int>num;
        vector<node>qwq;

        for(int j=1;j<=n;j++)
        {
            int l,r,e;cin>>l>>r>>e;
            num.push_back(l);num.push_back(r);
            qwq.push_back({l,r,e});
        }

        sort(num.begin(),num.end());

        for(auto x:num)
        if(unm[x]==0)
        unm[x]=(++idx);

        for(int i=1;i<=idx;i++)
        fa[i]=i;
        

        bool c=0;
        for(int j=1;j<=n;j++)
        {
            int l=qwq[j-1].l,r=qwq[j-1].r,e=qwq[j-1].e;
            int hl=unm[l],hr=unm[r];
            if(e==1)
            fa[find(hl)]=find(hr);
            
        }
        for(int j=1;j<=n;j++)
        {
            int l=qwq[j-1].l,r=qwq[j-1].r,e=qwq[j-1].e;
            int hl=unm[l],hr=unm[r];
            if(e==0)
            {
                if(find(hl)==find(hr))
                {
                    c=1;
                    break;
                }
            }
        }
        if(c==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    
}