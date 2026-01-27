#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ull ppp=131;
ll mod=1e9+7;
int n;
ll k;

struct matrix
{
    ll m[105][105];
    matrix(){
        memset(m,0,sizeof(m));
    }

    static matrix ident() //单位矩阵
    {
        matrix res;
        for(int i=1;i<=n;i++)
        res.m[i][i]=1;
        return res;
    }

    matrix operator*(const matrix &other) const //定义矩阵乘法
    {
        matrix res;
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
            {
                if(m[i][k]==0)
                continue;
                for(int j=1;j<=n;j++)
                {
                    res.m[i][j]=(res.m[i][j]+m[i][k]*other.m[k][j])%mod;
                }
            }
        return res;
    }
};

matrix qpow(matrix base,ll power)
{
    matrix res=matrix::ident();
    while (power>0)
    {
        if(power&1)
        res=res*base;
        base=base*base;
        power>>=1;
    }
    return res;
}


int main()
{
    cin>>n>>k;
    matrix qwq;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>qwq.m[i][j];
    }
    matrix ans=qpow(qwq,k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<ans.m[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}