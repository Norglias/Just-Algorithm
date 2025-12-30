#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;
ll awa[maxn];
ll p,q;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    cin>>awa[i];

    for(int i=2;i<=n;i++)
    {
        ll c=awa[i]-awa[i-1]; //差分处理
        if(c>0)
        //正项总和
        p+=c;          
        else
        //负项总和
        q-=c;
    }
    //每次只能在指定区间加一或者减一,所以先抵消差分数组中的正负值
    //把正项或者负项全部抵消后, 再加上剩下的数的绝对值,综合下来就是max(p,q)
    //总操作数取正值总和与负值总和的最大值
    ll ans1=max(p,q); 
    //数列最后的可能个数是正负项抵消后,剩下的那个值
    ll ans2=abs(p-q)+1;
    cout<<ans1<<"\n"<<ans2;

    return 0;
}