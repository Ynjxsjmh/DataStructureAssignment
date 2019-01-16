//
//  main.c
//  count
//
//  Created by DuanHaoHua on 17/5/23.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


void quick_sort(long long int *pnum, long long int l, long long int r);

long long int now;
int main(void)
{
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    long long int a[50002];
    for (int i = 0; i <= 50001; i ++)
    {
        a[i] = -1;
    }
    now = -1;
    long long int n;
    scanf("%lld", &n);
    for (int i = 0; i <= n - 1; i ++)
    {
        scanf("%lld", &a[i]);
    }
    quick_sort(a, 0, n - 1);
    long long int sum = 0;
    long long int temp = -1;
    now = a[0];
    sum ++;
    for (int i = 1; i <= n - 1; i ++)
    {
        temp = a[i];
        if (temp == now)
        {
            sum ++;
        }
        else
        {
            printf("%lld %lld\n", now, sum);
            sum = 1;
        }
        now = temp;
    }
    printf("%lld %lld\n", now, sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void quick_sort(long long int *pnum, long long int l, long long int r)
{
    if (l < r)
    {
        long long int i = l, j = r;
        long long int x = *(pnum + i);
        while (i < j)
        {
            while (i < j && *(pnum + j) >= x)
                j --;
            if (i < j)
                *(pnum + (i ++)) = *(pnum + j);
            while (i < j && *(pnum + i) < x)
                i ++;
            if (i < j)
                *(pnum + (j --)) = *(pnum + i);
        }
        *(pnum + i) = x;
        quick_sort(pnum, l, i - 1);
        quick_sort(pnum, i + 1, r);
    }
}
