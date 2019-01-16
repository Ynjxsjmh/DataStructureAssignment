#include<stdio.h>
#define e 110
#define kk 0
int weith[e] = {}, deeth[e] = {}, father[e] = {}, n;
struct stak
{
    int a[e], top;
    stak(){top = 0;}
    pushh(int x){a[++top] = x;}
    int popp(void){return a[top--];}
};
int deep(int x)
{
    if(deeth[father[x]] != 0)
        return deeth[father[x]] + 1;
    if(x == 1)
        return 1;
    return deep(father[x]) + 1;
}
int main(void)
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    int x, y, i;
    father[1] = 0;
    for(i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        father[y] = x;
    }
    int d, w, m;
    d = 0;
    w = 0;
    m = 0;
    for(i = 1; i <= n; i++)
    {
        deeth[i] = deep(i);
        weith[deeth[i]]++;
        if(deeth[i] > d)
            d = deeth[i];
    }
    for(i = 1; i <= d; i++)
        if(weith[i] > w)
            w = weith[i];
    scanf("%d%d", &x, &y);
    stak A, B;
    if(x == y)
        m = 0;
    else
    {
        int fx = x, fy = y;
        while(fx != 0)
        {
            A.pushh(fx);
            fx = father[fx];
            if(kk)printf("# %d  ", fx);
        }
        if(kk)printf("\n");
        while(fy != 0)
        {
            B.pushh(fy);
            fy = father[fy];
            if(kk)printf("$ %d  ", fy);
        }
        if(kk)printf("\n");
        while(fx == fy)
        {
            fx = A.popp();
            fy = B.popp();
            if(kk)printf("@ %d  ", fx);
        }
        m = (A.top + 1) * 2 + (B.top + 1);
    }
    printf("%d\n%d\n%d", d, w, m);
    return 0;
}
