#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;

int t;ll p[65];
int r=0;

void insert(int x)
{
    for(int i=62;i>=0;i--)
    {
        if((x>>i)&1)
        {
            if(!p[i])
            {
                p[i]=x;
                r++;
                break;
            }
            x^=p[i];
        }
    }
}


int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        bool ju=0;r=0;
        memset(p,0,sizeof(p));
        int num;cin>>num;
        for(int j=1;j<=num;j++)
        {
            ll x;cin>>x;
            if(x==0)
            ju=1;
            insert(x);
        }
        if(ju)
        {
            if(num==(1LL<<r))
            cout<<"maize"<<"\n";
            else
            cout<<"meow"<<"\n";
        }
        else
        {
            if(num==(1LL<<r)-1)
            cout<<"maize"<<"\n";
            else
            cout<<"meow"<<"\n";
        }
    }
}