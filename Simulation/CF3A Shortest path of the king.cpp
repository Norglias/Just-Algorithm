#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1000100;
const int MAXN=20020;
int chess[10][10];

int main()
{
    int sx,sy,ex,ey;
    string be,en;
    cin>>be;cin>>en;
    sy=be[0]-'a'+1;
    ey=en[0]-'a'+1;
    sx=be[1]-'0';
    ex=en[1]-'0';
    int dx=abs(ex-sx);
    int dy=abs(ey-sy);
    int ans=max(dx,dy);
    cout<<ans<<"\n";
    for(int i=1;i<=ans;i++)
    {
        if(ex>sx&&ey>sy)
        {
            sx+=1;sy+=1;
            cout<<"RU"<<"\n";
        }
        else if(ex>sx&&ey<sy)
        {
            sx+=1;sy-=1;
            cout<<"LU"<<"\n";
        }
        else if(ex<sx&&ey>sy)
        {
            sx-=1;sy+=1;
            cout<<"RD"<<"\n";
        }
        else if(ex<sx&&ey<sy)
        {
            sx-=1;sy-=1;
            cout<<"LD"<<"\n";
        }
        else if(ex==sx&&ey<sy)
        {
            sy-=1;
            cout<<"L"<<"\n";
        }
        else if(ex==sx&&ey>sy)
        {
            sy+=1;
            cout<<"R"<<"\n";
        }
        else if(ex<sx&&ey==sy)
        {
            sx-=1;
            cout<<"D"<<"\n";
        }
        else if(ex>sx&&ey==sy)
        {
            sx+=1;
            cout<<"U"<<"\n";
        }
    }
    return 0;
}