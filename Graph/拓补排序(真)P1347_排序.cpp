#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=80112002;
const int ppp=131;

int n,m;
vector<int>in(100,0);
int pos;
char re[40];
vector<int>qwq[maxn];

int solve(int x,vector<int>iinn)
{
    int c=0,ju=0;
    pos=0;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(iinn[i]==0)
        {
            q.push(i);
        }
    }
    
    int maxl=0;
    while(!q.empty())
    {
        if(q.size()>1)
        {
            ju=1;
        }
        int top=q.front();
        q.pop();
        re[++pos]=(char)('A'-1+top);
        c++;
        for(auto awa:qwq[top])
        {
            iinn[awa]--;
            if(iinn[awa]==0)
            q.push(awa);
        }
    }
    if(c<n)
    return -1;
    if(ju==1)
    return 0;
    return 1;
}

signed main()
{
    bool check=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        char su,cmp,sv;cin>>su>>cmp>>sv;
        if(check==1)
        continue;
        int u=su-'A'+1,v=sv-'A'+1;
        
        qwq[v].push_back(u);
        in[u]++;
        int ans=solve(i,in);
        if(ans==-1)
        {
            printf("Inconsistency found after %d relations.",i);
            check=1;
        }
        else if(ans==1)
        {
            printf("Sorted sequence determined after %d relations: ",i);
            for(int j=pos;j>=1;j--)
            cout<<re[j];
            
            cout<<'.';
            check=1;
        }
    }
    if(!check)
    cout<<"Sorted sequence cannot be determined.";
}

