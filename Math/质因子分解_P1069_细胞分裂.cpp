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

int n;
int prime[maxn];
vector<int>pm;
void init(int x,int pow)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int cnt=0;
            while(x%i==0)
            {
                x/=i;
                cnt++;
            }
            prime[i]+=cnt*pow;
            pm.push_back(i);
        }
    }
    if(x>1) 
    {
        prime[x]+=pow;
        pm.push_back(x);
    }
}

int m,mpow,ans=INF;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>m>>mpow;
    if(m==1)
    {
        cout<<0;
        return 0;
    }
    init(m,mpow);
    bool finalc=0;
    for(int t=1;t<=n;t++)
    {
        int cur,cans=-INF;cin>>cur;
        bool check=1;
        for(int i=0;i<pm.size();i++)
        {
            if(cur%pm[i]!=0)
            {
                check=0;
                break;
            }
            int ccnt=0;
            while(cur%pm[i]==0)
            {
                ccnt++;
                cur/=pm[i];
            }
            ccnt=(prime[pm[i]]+ccnt-1)/ccnt;
            cans=max(cans,ccnt);
        }
        if(check)
        {
            finalc=1;
            ans=min(ans,cans);
        }
    }
    if(!finalc)
    cout<<"-1";
    else
    cout<<ans;
    
}

