#include <iostream>
#include <stdio.h>
#define N 101
int power(int x, int n)
{
    int r = 1;
    for(int i = 0; i < n; i++)
    {
        r = r*x;
    }
    return r;
}
int main()
{
    int n, a[N], x, y, flag = 1;
    for(int i = 0; i < N; i++)
    {
        a[i] = -1;
    }
    a[1] = 1;
    FILE *fp = fopen("tree.in", "r");
    fscanf(fp, "%d", &n);
    for(int i = 0; i < n-1; i++)
    {
        fscanf(fp, "%d", &x);
        int j;
        for(j = 1; j < N; j++)
        {
            if(a[j] == x)
                break;
        }
        if(a[j*2] == -1)
        {
            fscanf(fp, "%d", &a[j*2]);
            if(j*2 > flag)
            {
                flag = j*2;
            }
        }
        else if(a[j*2+1] == -1)
        {
            fscanf(fp, "%d", &a[j*2+1]);
            if(j*2+1 > flag)
            {
                flag = j*2+1;
            }
        }
        else
        {
            std::cout << "wrong";
        }
    }
    fscanf(fp, "%d", &x);
    fscanf(fp, "%d", &y);
    for(int i = 1; i < N; i++)
    {
        if(a[i] == x)
        {
            x = i;
            break;
        }
    }
    for(int i = 1; i < N; i++)
    {
        if(a[i] == y)
        {
            y = i;
            break;
        }
    }
    //std::cout << x << y << flag;
    int width = 0, h = 1;
    for(int i = 1; ; i++)
    {
        int p = power(2,i);
        int q = power(2,i+1);
        if(2*(p - 1) > flag)
            break;
        int ii = 0;
        for(; p < q; p++)
        {
            if(a[p] != -1)
            {
                ii++;
            }
        }
        if(flag&&ii > width)
        {
            width = ii;
        }
    }
    int flag2 = flag;
    while(flag2 != 1)
    {
        flag2 = flag2/2;
        h++;
    }
    std::cout << h << width;
    int    xx = x;
    int yy = y;
    int b[100];
    for(int i = 0; xx != 1; i++)
    {
        xx = xx/2;
        b[i] = xx;
    }
    int timee = 0;
    int flagg = 0;
    int j = 0;
    for(int i = 0; yy !=1; i++)
    {
        timee++;
        yy = yy/2;
        for(; j < flag ; j++)
        {
            yy == b[j];
            flagg = 1;
            break;
        }
        if(flagg)
        {
            break;
        }
    }
    int rr = j*2 + timee;
    std::cout << rr << " " << timee;
}
