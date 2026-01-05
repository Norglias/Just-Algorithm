#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;
ull mod=212370440130137957ll;

ull hash1[maxn];

ull hhash(string a)
{
    ull ans=0,base=10;
    for(auto &x:a)
    {
        ans=(ans*base+(ull)x)%mod;
    }
    return ans;
}
int main()
{
    int n;cin>>n;
    string awa;
    for(int i=1;i<=n;i++)
    {
        cin>>awa;
        hash1[i]=hhash(awa);
    }
    sort(hash1+1,hash1+n+1);
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(hash1[i]!=hash1[i+1])
        cnt++;
    }
    cout<<cnt;
}