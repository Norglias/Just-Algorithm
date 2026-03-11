#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;

int result[maxn],cnt;

vector<int> b_next(string p)
{
    int le=p.length();
    vector<int>next(le,0);

    for(int i=1,j=0;i<le;i++)
    {
        while(j>0&&p[i]!=p[j])
        j=next[j-1];
        if(p[i]==p[j])
        j++;
        next[i]=j;
    }
    return next;
}


void kmp(string a,string tar)
{
    int la=a.length(),lt=tar.length();
    if(la<lt||lt==0)
    return;
    vector<int>next=b_next(tar);

    for(int i=0,j=0;i<la;i++)
    {
        while(a[i]!=tar[j]&&j>0)
        j=next[j-1];

        if(a[i]==tar[j])
        j++;

        if(j==lt)
        {
            result[++cnt]=i-lt+1;
            j=next[j-1];
        }
    }
}


signed main()
{
    string s1,s2;
    cin>>s1>>s2;
    kmp(s1,s2);
    for(int i=1;i<=cnt;i++)
    cout<<result[i]+1<<"\n";

    vector<int>awa=b_next(s2);
    for(int i=0;i<awa.size();i++)
    cout<<awa[i]<<" ";
}