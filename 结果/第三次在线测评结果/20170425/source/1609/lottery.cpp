//
//  main.c
//  lottery
//
//  Created by DuanHaoHua on 17/4/25.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int price[7];//获奖号码
int result[7];//存储结果

int judge(int a[]);

int main(void)
{
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    
    for (int i = 0; i <= 6; i ++)
    {
        result[i] = 0;
    }
    long long int n;
    scanf("%lld", &n);
    for (int i = 0; i <= 6; i ++)
    {
        scanf("%d", &price[i]);
    }
    int temp[7];
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j <= 6; j ++)
        {
            scanf("%d", &temp[j]);
        }
        int p = 0;
        p = judge(temp);
        if (p != 0)
        {
            int t = 7 - p;
            result[t] = result[t] + 1;
        }
    }
    for (int i = 0; i <= 5; i ++)
    {
        printf("%d ", result[i]);
    }
    printf("%d", result[6]);
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}

int judge(int a[])
{
    int sum = 0;
    for (int i = 0; i <= 6; i ++)
    {
        int temp = a[i];
        for (int j = 0; j <= 6; j ++)
        {
            int temp2 = price[j];
            if (temp == temp2)
            {
                sum ++;
            }
        }
    }
    return sum;
}
