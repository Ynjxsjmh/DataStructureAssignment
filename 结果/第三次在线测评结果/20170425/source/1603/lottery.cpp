#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    FILE* f1;
    FILE* f2;
    f1 = fopen("lottery.in", "r");
    f2 = fopen("lottery.out", "w");
    int st[10], a[10], n;
    fscanf(f1, "%d", &n);
    for(int i = 1;i <= 7;i++)
        fscanf(f1, "%d", st + i);
    sort(st + 1, st + 8);
    int jiang[10] = {};
    while(n--)
    {
        for(int i = 1;i <= 7;i++)
            fscanf(f1, "%d", a + i);
        sort(a + 1, a + 8);
        int p1 = 1, p2 = 1, m = 0;
        while(p1 <= 7 && p2 <= 7)
        {
            if(st[p1] < a[p2])
            {
                p1++;
                continue;
            }
            if(st[p1] > a[p2])
            {
                p2++;
                continue;
            }
            if(st[p1] == a[p2])
            {
                p2++;
                m++;
                continue;
            }
        }
        jiang[m]++;
    }
    for(int i = 7;i > 1;i--)
        fprintf(f2, "%d ", jiang[i]);
    fprintf(f2, "%d\n", jiang[1]);
    return 0;
}
