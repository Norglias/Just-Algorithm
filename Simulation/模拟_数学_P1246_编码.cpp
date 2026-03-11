#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ll mod=1e9+7;
const int ppp=131;
string qwq;
int p[maxn];
int cnt=1;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>qwq;
    int l=qwq.length();
    for(int i=0;i<l-1;i++)
    if(qwq[i]>=qwq[i+1])
    {
        cout<<0;
        return 0;
    }
    string cur="a";
    while(1)
    {
        if(cur==qwq)
        {
            cout<<cnt;
            break;
        }
        int le=cur.length();
        cur[le-1]++;

        for(int i=le-1;i>0;i--)
        {
            if(cur[i]>'z'-(le-1-i))
            cur[i-1]++;
        }
        for(int i=0;i<=le-1;i++)
        {
            if(cur[0]>'z'-(le-1-i))
            {
                cur=cur+"1";
                for(int j=0;j<=le;j++)
                cur[j]='a'+j;
            }
            if(cur[i]>'z'-(le-1-i)&&i!=0)
            cur[i]=cur[i-1]+1;
        }
        cnt++;
    }
}

