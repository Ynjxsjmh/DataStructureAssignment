//
//  main.c
//  catchcow
//
//  Created by DuanHaoHua on 17/4/25.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int tim[100005];
int visited[100005];
int queen[100005];
int head, tail;

void push(int item);
int isempty();
int pop();

int main(void)
{
    freopen("catchcow.in", "r", stdin);
    freopen("catchcow.out", "w", stdout);
    
    for (int i = 0; i <= 100004; i ++)
    {
        tim[i] = 0;
        visited[i] = 0;
        queen[i] = 0;
    }
    
    int n, k;
    scanf("%d%d", &n, &k);
    
    head = 0;
    tail = 0;
    push(n);
    visited[n] = 1;
    int temp;
    
    while (!isempty())
    {
        int result = pop();
        if (result == k)
        {
            printf("%d", tim[result]);
            break;
        }
        else
        {
            temp = result - 1;
            if (visited[temp] == 0 && temp >= 0)
            {
                push(temp);
                tim[temp] = tim[result] + 1;
                visited[temp] = 1;
            }
            temp = result + 1;
            if (visited[temp] == 0 && temp <= 100000)
            {
                push(temp);
                tim[temp] = tim[result] + 1;
                visited[temp] = 1;
            }
            temp = 2 * result;
            if (visited[temp] == 0 && temp <= 100000)
            {
                push(temp);
                tim[temp] = tim[result] + 1;
                visited[temp] = 1;
            }
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}

int isempty()
{
    if (head == tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int item)
{
    queen[tail ++] = item;
}

int pop()
{
    return queen[head ++];
}

