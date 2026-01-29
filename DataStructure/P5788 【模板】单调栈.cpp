#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=10000010;
const ull ppp=131;

int n;
int num[maxn];
int R[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    stack<int>st;
    for(int i=1;i<=n;i++)
    cin>>num[i];

    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&num[st.top()]<=num[i])
        st.pop();
        R[i]=st.empty()?0:st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++)
    cout<<R[i]<<" ";
}