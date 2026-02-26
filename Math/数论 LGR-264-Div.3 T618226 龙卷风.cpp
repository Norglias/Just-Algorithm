#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int t;
int n,m;
int num[maxn];

int gcd(int a,int b)
{
    while(b)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

signed main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int ans=0;
        cin>>n>>m;
        map<int,int>times;
        set<int>qwq;
        for(int j=1;j<=n;j++)
        {
            cin>>num[j];
            qwq.insert(num[j]);
            times[num[j]]++;
        }
        int kind=qwq.size();
        for(int k=kind;k<=m;k++)
        {   
            if(kind==1)
            {
                ans=m;
                break;
            }
            int gcdk=gcd(n,k); //关键
            if(n%gcdk)
            continue;
            int sss=0,awa=n/gcdk;
            for(auto &x:qwq)
            {
                if(times[x]%awa!=0)
                {
                    sss=1;
                    break;
                }
            }
            if(!sss)
            ans++;
        }
        cout<<ans<<"\n";
    }

}