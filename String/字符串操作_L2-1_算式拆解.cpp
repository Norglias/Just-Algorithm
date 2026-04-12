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

string qwq;
int dpos[maxn];
int cutpo[maxn],pos;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>qwq;
    int depth=0;
    while(1)
    {
        int r=qwq.find(')');
        if(r==string::npos)
        break;
        int l=qwq.rfind('(',r);
        if(l==string::npos)
        break;


        for(int i=l;i<=r;i++)
        {
            if(qwq[i]!='('&&qwq[i]!=')'&&qwq[i]!='#')
            cout<<qwq[i];
        }
        cout<<"\n";

        string awa=qwq.substr(0,l)+"#"+qwq.substr(r+1);
        qwq=awa;
    }


}