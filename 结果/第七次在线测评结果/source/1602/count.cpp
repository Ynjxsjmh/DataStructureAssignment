#include<stdio.h>
#define e 50010
#define key 0
int a[e] = {}, b[e] = {}, c[e], n;
int main(void)
{
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    scanf("%d", &n);
    int i, j, x, m = 0, k, y, tail;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        j = 0;
        while(j < m && a[j] != x)
            j++;
        a[j] = x;
        if(j == m)
            m++;
        b[j]++;
    }
    //printf("@@  %d", m);
    for(i = 0; i < m; i++)
        c[i] = i;
    k = m - 1;
    while(k != 0)
    {
        tail = k;
        k = 0;
        for(i = 0; i < tail; i++)
        {
            if(a[i] > a[i + 1])
            {
                if(key)printf("\n ##  %d %d %d %d \n", i, a[i], i + 1, a[i + 1]);
                y = a[i];
                a[i] = a[i + 1];
                a[i + 1] = y;
                y = c[i];
                c[i] = c[i + 1];
                c[i + 1] = y;
                k = i;
            }
        }
    }
    for(i = 0; i < m; i++)
        printf("%d %d\n", a[i], b[c[i]]);
    return 0;
}
