#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;

int n,k;
int aa[maxn],bb[maxn],cnt;
ll L[maxn],R[maxn];

ll find()
{
    ll cutpo=0;
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        if(bb[i]<k)
        {
            cutpo=i;
            while(!s.empty())s.pop();
            L[i]=0;
            continue;
        }
        while (!s.empty()&&aa[s.top()]<aa[i])
        s.pop();
        int lebound=s.empty()?cutpo:s.top();
        L[i]=i-lebound-1;
        s.push(i);
    }
    while(!s.empty())s.pop();
    cutpo=n+1;
    for(int i=n;i>=1;i--)
    {
        if(bb[i]<k)
        {
            cutpo=i;
            while(!s.empty())s.pop();
            R[i]=0;
            continue;
        }
        while(!s.empty()&&aa[s.top()]<aa[i])
        s.pop();
        int rebound=s.empty()?cutpo:s.top();
        R[i]=rebound-i-1;
        s.push(i);
    }

    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        if(bb[i]<k)
        continue;

        ll l=L[i],r=R[i];
        ans+=(min(l,r)+1);
        if(r>0)
        ans+=(min(l,r-1)+1);
        if(l>0)
        ans+=(min(l-1,r)+1);
    }
    return ans;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>aa[i];
    for(int i=1;i<=n;i++)
    cin>>bb[i];
    
    cout<<find();
}