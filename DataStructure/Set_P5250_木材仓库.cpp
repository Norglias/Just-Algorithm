#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=1e18+10;
typedef pair<ll,int> PAIR;
const ull mod=212370440130137957ll;
const int ppp=131;

int m,t;
set<int>s;
set<int>::iterator a1,a2,a3;
signed main()
{
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op>>t;
        if(op==1)
        {
            bool check=s.insert(t).second;
            if(!check)
            cout<<"Already Exist\n";
        }
        else if(op==2)
        {
            if(s.empty())
            {
                cout<<"Empty\n";
                continue;
            }
            if(s.find(t)!=s.end())
            {
                cout<<t<<"\n";
                s.erase(s.find(t));
            }
            else
            {
                a1=a2=a3=s.lower_bound(t);
                if(a1==s.begin())
                {
                    cout<<*a1<<"\n";
                    s.erase(a1);
                }
                else if(a1==s.end())
                {
                    cout<<*(--a1)<<"\n";
                    s.erase(a1);
                }
                else if(*a2-t<t-*(--a3))
                {
                    cout<<*a1<<"\n";
                    s.erase(a1);
                }
                else
                {
                    cout<<*(--a1)<<"\n";
                    s.erase(a1);
                }
            }
        }
    }
}