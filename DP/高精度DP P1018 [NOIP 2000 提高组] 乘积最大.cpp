#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ll INF=1e8+10;

typedef vector<int> bignum;
#define int long long
int n,k;
bignum dp[100][100];

bignum init(string a)
{
    int le=a.length();
    bignum result;
    for(int i=0;i<le;i++)
    result.push_back(a[i]-'0');

    reverse(result.begin(),result.end());
    return result;
}

bignum h_mul(const bignum &a,const bignum &b)
{
    int sa=a.size();
    int sb=b.size();
    
    bignum re(sa+sb+1,0);
    for(int i=0;i<sa;i++)
    {
        for(int j=0;j<sb;j++)
        {
            re[i+j]+=a[i]*b[j];
        }
    }
    int jin=0;
    for(int i=0;i<sa+sb;i++)
    {
        ll cur=re[i]+jin;
        re[i]=cur%10;
        jin=cur/10;
    }

    while (re.size()>1&&re.back()==0)
    re.pop_back();
    
    return re;
}

bool cmp(const bignum &a,const bignum &b)
{
    if(a.size()>b.size())
    return 1;
    else if(a.size()<b.size())
    return 0;

    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]>b[i])
        return 1;
        else if(a[i]<b[i])
        return 0;
    }
    return 0;
}

signed main()
{
    cin>>n>>k;
    string a;cin>>a;
    int le=a.length();
    a=" "+a;
    //dp[i][k]表示前i个数，切了k次后的乘积最大值
    for(int i=1;i<=50;i++)
    {
        string sub=a.substr(1,i);
        bignum num=init(sub);
        dp[i][0]=num;
    }


    for(int l=1;l<=k;l++)
    {
        for(int i=l+1;i<=le;i++)
        {
            for(int j=l;j<i;j++)
            {
                string sub=a.substr(j+1,i-j);
                bignum num=init(sub);
                bignum cur=h_mul(dp[j][l-1],num);
                if(cmp(cur,dp[i][l]))
                dp[i][l]=cur;
            }
        }
    }
    
    for(int i=dp[n][k].size()-1;i>=0;i--)
    cout<<dp[n][k][i];
}