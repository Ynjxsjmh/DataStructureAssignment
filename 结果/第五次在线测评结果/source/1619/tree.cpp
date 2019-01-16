#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
#define maxn 1100
#define sf scanf
int dep[maxn],fa[maxn],cal[maxn],n;
vector<int>g[maxn];
int lca(int x,int y)
{
    int tx=dep[x];
    int ty=dep[y];
    while(tx>ty)
    {
        x=fa[x];
        tx--;
    }
    while(ty>tx)
    {
        y=fa[y];
        ty--;
    }
    while(x!=y)
    {
        x=fa[x];
        y=fa[y];
    }
    return x;
}
int ans1,ans2;
void dfs(int now,int pre)
{
    dep[now]=dep[pre]+1;
    ans1=max(ans1,dep[now]);
    cal[dep[now]]++;
    ans2=max(ans2,cal[dep[now]]);
    fa[now]=pre;
    for(int i=0;i<g[now].size();i++)
    {
        if(g[now][i]==pre) continue;
        dfs(g[now][i],now);
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ans1=0;
    ans2=0;
    int a,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);

    scanf("%d%d",&a,&b);
    printf("%d\n",ans1);
    printf("%d\n",ans2);
    int con=lca(a,b);
    int len=2*(dep[a]-dep[con])+dep[b]-dep[con];
    printf("%d\n",len);
    return 0;
}
/*
10
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
6 10
1 1
*/
