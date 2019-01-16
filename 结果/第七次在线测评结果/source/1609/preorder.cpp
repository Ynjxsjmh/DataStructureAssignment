//
//  main.c
//  preorder
//
//  Created by DuanHaoHua on 17/5/23.
//  Copyright © 2017年 DuanHaoHua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct b_tree
{
    char data;
    struct b_tree *left_child;
    struct b_tree *right_child;
};

void pre_order(struct b_tree *root);
void create(struct b_tree **t, char m[], char p[], int left_m, int right_m, int left_p, int right_p);


int main(void)
{
    freopen("preorder.in", "r", stdin);
    freopen("preorder.out", "w", stdout);

    char mid[20];
    char post[20];
    scanf("%s", mid);
    scanf("%s", post);
    int len = 0;
    int len2 = 0;
    for (int i = 0; i <= 19; i ++)
    {
        char temp = mid[i];
        if (temp == '\0')
            break;
        len ++;
    }
    for (int i = 0; i <= 19; i ++)
    {
        char temp = post[i];
        if (temp == '\0')
            break;
        len2 ++;
    }
    struct b_tree *root;
    create(&root, mid, post, 0, len - 1, 0, len2 - 1);
    pre_order(root);
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void pre_order(struct b_tree *p)
{
    if (p != NULL)
    {
        printf("%c", p -> data);
        pre_order(p -> left_child);
        pre_order(p -> right_child);
    }
}

void create(struct b_tree **t, char m[], char p[], int left_m, int right_m, int left_p, int right_p)
{
    *t = (struct b_tree*)malloc(sizeof(struct b_tree));
    (*t) -> data = p[right_p];
    (*t) -> left_child = NULL;
    (*t) -> right_child = NULL;
    int temp = left_m;
    while (m[temp] != p[right_p])
    {
        temp ++;
    }
    int len = temp - left_m;
    if (temp > left_m)
    {
        create(&(*t) -> left_child, m, p, left_m, temp - 1, left_p, left_p + len - 1);
    }
    if (temp < right_m)
    {
        create(&(*t) -> right_child, m, p, temp + 1, right_m, left_p + len, right_p - 1);
    }
}
