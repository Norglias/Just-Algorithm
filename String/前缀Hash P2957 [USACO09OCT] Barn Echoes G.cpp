#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;
const int ppp=131;

ull h1[MAXN],p1[MAXN],h2[MAXN],p2[MAXN]; 

void init(string s,ull h[],ull p[])
{
    p[0]=1;
    h[0]=0;
    for(int i=1;i<=s.length();i++)
    {
        p[i]=p[i-1]*ppp;
        h[i]=h[i-1]*ppp+s[i-1];
    }
}

ull hhh(ull h[],ull p[],int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    string a,b;
    cin>>a>>b;

    init(a,h1,p1);
    init(b,h2,p2);
    int ale=a.length(),ble=b.length();
    int ans=0;
    for(int i=1;i<=min(ale,ble);i++)
    {
        if(hhh(h1,p1,1,i)==hhh(h2,p2,ble-i+1,ble))
        ans=max(ans,i);
    }
    for(int i=1;i<=min(ale,ble);i++)
    {
        if(hhh(h2,p2,1,i)==hhh(h1,p1,ale-i+1,ale))
        ans=max(ans,i);
    }
    cout<<ans;
}