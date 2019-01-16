#include<cstdio>
#include<algorithm>
#define MAXN 7001
using namespace std;
int n;
int x[MAXN],y[MAXN],r[MAXN];
int p[MAXN];
int num;
long long d;
int getfa(int x)
{
    if(p[x]==x)
        return x;
    return p[x]=getfa(p[x]);
}
void uni(int x,int y)
{
    p[getfa(x)]=getfa(y);
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d %d %d",&x[i],&y[i],&r[i]);
    num=n;
    for(i=1;i<=n;i++)
        p[i]=i;
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++)
        {
            if(getfa(i)==getfa(j))
                continue;
            d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if(d<=(r[i]+r[j])*(r[i]+r[j]))
            {
                uni(i,j);
                num--;
            }
        }
    printf("%d\n",num);
    return 0;
}
