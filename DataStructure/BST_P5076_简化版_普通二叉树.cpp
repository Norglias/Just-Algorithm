#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll INF=2147483647;
typedef pair<ll,int> PAIR;

int q;
int sum;
struct node
{
    int l,r,w,time,size;
};
node tree[maxn];

void insert(int pos,int num)
{
    tree[pos].size++;
    if(tree[pos].w==num)
    {
        tree[pos].time++;
        return;
    }
    if(tree[pos].w>num)
    {
        if(tree[pos].l==0)
        {
            sum++;
            tree[sum].w=num;
            tree[sum].time=tree[sum].size=1;
            tree[pos].l=sum;
        }
        else
        insert(tree[pos].l,num);
    }
    if(tree[pos].w<num)
    {
        if(tree[pos].r==0)
        {
            sum++;
            tree[sum].w=num;
            tree[sum].time=tree[sum].size=1;
            tree[pos].r=sum;
        }
        else
        insert(tree[pos].r,num);
    }
}

int findpos(int pos,int x)
{
    if(pos==0)
    return 0;

    if(tree[pos].w==x)
    return tree[tree[pos].l].size;
    else if(tree[pos].w>x)
    return findpos(tree[pos].l,x);
    else
    return findpos(tree[pos].r,x)+tree[tree[pos].l].size+tree[pos].time;
}

int findnum(int pos,int x)
{
    if(pos==0)
    return INF;

    if(tree[tree[pos].l].size>=x)
    return findnum(tree[pos].l,x);
    if(tree[tree[pos].l].size+tree[pos].time>=x)
    return tree[pos].w;
    return findnum(tree[pos].r,x-tree[tree[pos].l].size-tree[pos].time);
}

int findsmall(int pos,int x,int ans)
{
    if(tree[pos].w>=x)
    {
        if(tree[pos].l==0)
        return ans;
        else
        return findsmall(tree[pos].l,x,ans);
    }
    else
    {
        if(tree[pos].r==0)
        return (tree[pos].w<x)?tree[pos].w:ans;
        if(tree[pos].time!=0)
        return findsmall(tree[pos].r,x,tree[pos].w);
        else
        return findsmall(tree[pos].r,x,ans);
    }
}

int findbig(int pos,int x,int ans)
{
    if(tree[pos].w<=x)
    {
        if(tree[pos].r==0)
        return ans;
        else
        return findbig(tree[pos].r,x,ans);
    }
    else
    {
        if(tree[pos].l==0)
        return (tree[pos].w>x)?tree[pos].w:ans;
        if(tree[pos].time!=0)
        return findbig(tree[pos].l,x,tree[pos].w);
        else
        return findbig(tree[pos].l,x,ans);
    }
}

signed main()
{
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x;cin>>x;
            cout<<findpos(1,x)+1<<"\n";
        }
        else if(op==2)
        {
            int x;cin>>x;
            cout<<findnum(1,x)<<"\n";
        }
        else if(op==3)
        {
            int x;cin>>x;
            cout<<findsmall(1,x,-INF)<<"\n";
        }
        else if(op==4)
        {
            int x;cin>>x;
            cout<<findbig(1,x,INF)<<"\n";
        }
        else if(op==5)
        {
            int x;cin>>x;
            if(sum==0)
            {
                sum++;
                tree[1].size=tree[1].time=1;
                tree[1].w=x;
            }
            else
            insert(1,x);
        }
    }
}