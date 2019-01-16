#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long x[7010], y[7010], r[7010], father[7010];
int bfind(int a)
{
    int b = father[a];
    while(b != father[b])
        b = father[b];
    father[a] = b;
    return b;
}
void join(int a, int b)
{
    father[bfind(b)] = bfind(a);
}
int main()
{
    FILE* f1;
    FILE* f2;
    f1 = fopen("circle.in", "r");
    f2 = fopen("circle.out", "w");
    int n;
    fscanf(f1, "%d", &n);
    for(int i = 1;i <= n;i++)
        fscanf(f1, "%lld %lld %lld", x + i, y + i, r + i);
    for(int i = 1;i <= n;i++)
        father[i] = i;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j < i;j++)
            if((r[i] + r[j]) * (r[i] + r[j]) >= (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) && bfind(i) != bfind(j))
                join(i, j);
    int sum = 0;
    for(int i = 1;i <= n;i++)
        if(father[i] == i)
            sum++;
    fprintf(f2, "%d\n", sum);
    return 0;
}
