#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

int n;

int main()
{
    cin>>n;
    int now=0,ans=INT_MIN;
    //标准Kadane算法求最大字段和
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        now+=a;
        if(now>ans)
        ans=now;
        //如果now小于0,它对后面的序列就没有任何增益效果了,所以清零
        if(now<0)
        now=0;
    }
    cout<<ans;
}