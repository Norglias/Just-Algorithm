#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;

ll sum[maxn];
int m;
inline int binary(int l,int r,ll awa)
{
    if(l>r)
    return -1;
    int mid=(l+r)/2;
    if(sum[mid]-awa==m)
    return mid;
    else if(sum[mid]-awa>m)
    return binary(l,mid-1,awa);
    else if(sum[mid]-awa<m)
    return binary(mid+1,r,awa);
}

int main()
{
    cin>>m;
    int pos1=1,pos2=0;
    for(int i=1;i<=m/2+1;i++)
    sum[i]=sum[i-1]+i;

    for(int i=1;i<=m/2+1;i++)
    {
        ll ans=binary(i,m/2+1,sum[i]);
        if(ans!=-1)
        {
            cout<<i+1<<" "<<ans<<"\n";
        }
    }
    return 0;
}