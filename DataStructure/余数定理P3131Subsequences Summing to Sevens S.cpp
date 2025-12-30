#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

ll fir[7],last[7];

int main()
{
    memset(fir,-1,sizeof(fir));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int qwq=0;
    fir[0]=0;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        //运用了余数定理:
        //(sum[m]-sum[n])%7=0,有sum[m]%7=sum[n]%7
        //把sum余数相同的位置记录一下,再用一遍循环找出位置相差最大的
        qwq=(qwq+a)%7;
        if(fir[qwq]==-1)
        {
            fir[qwq]=i;
        }
        else
        //随着数的增大会不断更新
        {
            last[qwq]=i;
        }
    }
    int ans=0;
    for(int i=0;i<=6;i++)
    {
        int len=last[i]-fir[i];
        ans=max(ans,len);
    }
    cout<<ans;
    return 0;
}