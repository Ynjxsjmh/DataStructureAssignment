#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstring>
using namespace std;
#define maxn 7100
#define sint long long
int fa[maxn],n;
long long x[maxn],y[maxn],r[maxn];
int getfa(int now)
{
    if(fa[now]==now) return now;
    return fa[now]=getfa(fa[now]);
}
long long get(long long tmp)
{
    return tmp*tmp;
}
bool check(int a,int b)
{
    if(get(r[a]+r[b])>=get(x[a]-x[b])+get(y[a]-y[b]))
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int root;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        cin>>x[i]>>y[i]>>r[i];
        for(int j=1;j<i;j++)
        {
            if(check(i,j))
            {
                if(getfa(i)==getfa(j)) continue;
                fa[i]=getfa(j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        getfa(i);
        if(fa[i]==i)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
3
0 0 2
3 4 3
10 10 2
*/
