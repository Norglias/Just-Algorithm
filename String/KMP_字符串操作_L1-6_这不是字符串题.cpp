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

int n,m,ans;

vector<int>build(string p)
{
    int le=p.length();
    vector<int>nxt(le,0);
    for(int i=1,j=0;i<le;i++)
    {
        while(j>0&&p[i]!=p[j])
        j=nxt[j-1];
        if(p[i]==p[j])
        j++;
        nxt[i]=j;
    }
    return nxt;
}

int kmp(string a,string cur)
{
    int ale=a.length(),cle=cur.length();
    if(ale<cle||cle==0)
    return -1;
    vector<int>nxt=build(cur);

    for(int i=0,j=0;i<ale;i++)
    {
        while(a[i]!=cur[j]&&j>0)
        j=nxt[j-1];
        if(a[i]==cur[j])
        j++;
        if(j==cle)
        {
            return i-cle+1;   
        }
    }
    return -1;
}

signed main()
{
    cin>>n>>m;
    string qwq="";
    
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        qwq+=(char)('a'+x-1);
    }
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int le;cin>>le;
            string cur="";
            for(int j=1;j<=le;j++)
            {
                int x;cin>>x;
                cur+=(char)('a'+x-1);
            }
            int pos=kmp(qwq,cur);
            int lele;cin>>lele;
            string awa="";
            for(int j=1;j<=lele;j++)
            {
                int x;cin>>x;
                awa+=(char)('a'+x-1);
            }
            if(pos==-1)
            continue;
            qwq.replace(pos,le,awa);
        }
        else if(op==2)
        {
            if(qwq.length()<2)
            continue;
            string re="";
            for(int i=0;i<qwq.length()-1;i++)
            {
                re+=qwq[i];
                if((qwq[i]+qwq[i+1])%2==0)
                {
                    re+=(char)((qwq[i]+qwq[i+1])/2);
                }
            }
            re+=qwq[qwq.length()-1];
            qwq=re;
        }
        else if(op==3)
        {
            int l,r;cin>>l>>r;
            l-=1,r-=1;
            reverse(qwq.begin()+l,qwq.begin()+r+1);
        }
    }
    for(int i=0;i<qwq.length();i++)
    {
        if(i==qwq.length()-1)
        cout<<qwq[i]-'a'+1;
        else
        cout<<qwq[i]-'a'+1<<" ";
    }
}