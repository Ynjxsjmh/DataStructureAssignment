//
//  main.c
//  circle
//
//  Created by DuanHaoHua on 17/5/9.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[7005], y[7005], r[7005];
int con[7005][7005];
int con2[7005][7005];
int visited[7005];
int n;
int isall();
int find();

void dfs(int i);

double length(int x1, int x2, int y1, int y2);
int main(void)
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    
    for (int i = 0; i <= 7004; i ++)
    {
        x[i] = -1;
        y[i] = -1;
        r[i] = -1;
    }
    
    scanf("%d", &n);
    for (int i = 0; i <= n - 1; i ++)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
        scanf("%d", &r[i]);
    }
    
    for (int i = 0; i <= n - 1; i ++)
    {
        for (int j = 0; j <= n - 1; j ++)
        {
            ///////////////
            if (i == j)
                continue;
            ///////////////
            int x1, x2, y1, y2, r1, r2;
            x1 = x[i];
            x2 = x[j];
            y1 = y[i];
            y2 = y[j];
            r1 = r[i];
            r2 = r[j];
            double temp;
            temp = length(x1, x2, y1, y2);
            if (temp <= r1 + r2)
            {
                con[i][j] = 1;
                con[j][i] = 1;
            }
        }
        
    }

    //dfs(0);
    
    for (int i = 0; i <= n - 1; i ++)
    {
        visited[i] = -1;
    }
    
    int tim;
    for (tim = 0; ; tim ++)
    {
        if (isall())
        {
            break;
        }
        else
        {
            
            dfs(find());
            
        }
    }
    tim ++;
    printf("%d", tim);
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}


double length(int x1, int x2, int y1, int y2)
{
    double result = 0;
    double temp = (x1 - x2) * (x1 - x2);
    double temp2 = (y1 - y2) * (y1 - y2);
    result = sqrt(temp + temp2);
    return result;
}

int isall()
{
    for (int i = 0; i <= n - 1; i ++)
    {
        if (visited[i] == 0)
        {
            break;
            return 0;
        }
    }
    return 1;
}

int find()
{
    int i;
    for (i = 0; i <= n - 1; i ++)
    {
        if (visited[i] == 0)
        {
            break;
            return i;
        }
    }
    return -1;

    
}

void dfs(int temp4)
{
    visited[temp4] = 1;
    for(int j = 0; j <= n - 1; j ++)
    {
        if (visited[j] == -1)
            break;
        if(con[temp4][j] != 0 && visited[j] == 0)
            dfs(j);
    }
}

