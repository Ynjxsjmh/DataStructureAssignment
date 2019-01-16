//
//  main.c
//  tree
//
//  Created by DuanHaoHua on 17/5/9.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int connection[200][200];
int deep[200];
int deep_sum[200];
int n;
int max_board;
int max_deep;

void func(int i);

int main(void)
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i ++)
    {
        int temp = 0;
        int temp2 = 0;
        scanf("%d%d", &temp, &temp2);
        connection[temp][temp2] = 1;
        connection[temp2][temp] = 1;
    }
    int u = 0;
    int v = 0;
    scanf("%d%d", &u, &v);
    deep[1] = 1;
    func(1);
    for (int i = 1; i <= n; i ++)
    {
        deep_sum[deep[i]] ++;
        if (deep_sum[deep[i]] > max_board)
        {
            max_board = deep_sum[deep[i]];
        }
        if (deep[i] > max_deep)
        {
            max_deep = deep[i];
        }
    }
    int result = 0;
    result = (deep[u] - 1) * 2 + deep[v] - 1;
    printf("%d\n", max_deep);
    printf("%d\n", max_board);
    printf("%d", result);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void func(int temp)
{
    for (int i = 1; i <= n; i ++)
    {
        if (connection[temp][i] && deep[i] == 0)
        {
            deep[i] = deep[temp] + 1;
            func(i);
        }
    }
}
