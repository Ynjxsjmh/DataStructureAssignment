#include<stdio.h>
int main(void)
{
    int n, i, j, grade[8] = {}, aim[7];
    int m, k;
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    scanf("%d", &n);
    for(i = 0; i < 7; i++)
        scanf("%d", &aim[i]);
    for(i = 0; i < n; i++)
    {
        m = 0;
        for(j = 0; j < 7; j++)
        {
            scanf("%d", &k);
            for(int t = 0; t < 7; t++)
                if(k == aim[t])
                m++;
            //printf("\n m:%d\n", m);
        }
        grade[m]++;
    }
    for(i = 7; i > 0; i--)
        printf("%d", grade[i]);
    return 0;
}
