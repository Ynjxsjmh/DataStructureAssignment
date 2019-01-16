#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 7000+5;

class node{
public:
    int x,y;
    int r;
};

int oj(node a,node b)
{
    long long d1,d2;
    d1 = a.r + b.r;
    d2 = (a.x-b.x)*(a.x-b.x) +(a.y-b.y)*(a.y-b.y);
    if(d1*d1 >= d2)
        return 1;
    return 0;
}



node circle[maxn];
int vis[maxn];


int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int T;
    int cnt = 0;
    //memset(st,0,sizeof(st));
    memset(vis,0,sizeof(vis));
    scanf("%d",&T);
    for(int i = 1; i <= T;i++)
        scanf("%d %d %d",&circle[i].x,&circle[i].y,&circle[i].r);
    for(int i = 1; i <= T;i++)
    {
        if(!vis[i])
        {
            cnt++;
            vis[i] = 1;
        }
        for(int j = 1;j <= T;j++)
        {
            if(!vis[j])
            {
                if(oj(circle[i],circle[j]))
                {
                    vis[j] = 1;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
