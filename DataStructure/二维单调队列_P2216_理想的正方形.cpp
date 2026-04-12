#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0)
#define CT cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int maxn=2000010;
const ll INF=1e18+10;
typedef pair<int,int> PAIR;
const int mod=1e9+7;
const int ppp=131;

int a,b,n;
int num[1005][1005];
int qu[1005];
int res_max[1005][1005];
int res_min[1005][1005];

signed main()
{
    IOS;CT;
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
        cin>>num[i][j];

    for(int i=1;i<=a;i++)
    {
        memset(qu,0,sizeof(qu));
        int head=1,tail=0;
        for(int j=1;j<=b;j++)
        {
            while(head<=tail&&qu[head]<=j-n)
            head++;
            while(head<=tail&&num[i][qu[tail]]<=num[i][j])
            tail--;
            qu[++tail]=j;

            if(j>=n)
            res_max[i][j]=num[i][qu[head]];
        }
        head=1,tail=0;
        memset(qu,0,sizeof(qu));
        for(int j=1;j<=b;j++)
        {
            while(head<=tail&&qu[head]<=j-n)
            head++;
            while(head<=tail&&num[i][qu[tail]]>=num[i][j])
            tail--;
            qu[++tail]=j;

            if(j>=n)
            res_min[i][j]=num[i][qu[head]];
        }
    }

    int ans=INF;
    for(int i=n;i<=b;i++)
    {
        int maxq[1005],minq[1005];
        int head1=1,tail1=0,head2=1,tail2=0;
        for(int j=1;j<=a;j++)
        {
            while(head1<=tail1&&maxq[head1]<=j-n)
            head1++;
            while(head1<=tail1&&res_max[maxq[tail1]][i]<=res_max[j][i])
            tail1--;
            maxq[++tail1]=j;

            while(head2<=tail2&&minq[head2]<=j-n)
            head2++;
            while(head2<=tail2&&res_min[minq[tail2]][i]>=res_min[j][i])
            tail2--;
            minq[++tail2]=j;

            if(j>=n)
            {
                int awa=res_max[maxq[head1]][i],asa=res_min[minq[head2]][i];
                ans=min(ans,awa-asa);
            }
        }
    }
    cout<<ans;
}