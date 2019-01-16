#include<stdio.h>
#include<math.h>
#define e 7100
int n;
int father[e], x[e], y[e], r[e];
int pan(int i, int j)
{
    int a, b, c, d;
    a = x[i] - x[j];
    b = y[i] - y[j];
    c = r[i] + r [j];
    d = sqrt((a * a) + (b * b));
    if(d > c)
        return 0;
    return 1;
}
int main(void)
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; i++)
    {
        scanf("%d%d%d", &(x[i]), &(y[i]), &(r[i]));
        father[i] = -1;
        for(j = 0; j < i; j++)
        {
            if(pan(i, j))
                father[j] = i;
        }
    }
    int m = 0;
    for(i = 0; i < n; i++)
        if(father[i] == -1)
        m++;
    printf("%d", m);
    return 0;
}
