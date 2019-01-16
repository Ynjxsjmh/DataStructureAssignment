#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long sh[50010];
int main()
{
    FILE *f1, *f2;
    f1 = fopen("count.in", "r");
    f2 = fopen("count.out", "w");
    int n;
    fscanf(f1, "%d", &n);
    for(int i = 1;i <= n;i++)
        fscanf(f1, "%lld", sh + i);
    sort(sh + 1, sh + n + 1);
    int c = 1;
    for(int i = 2;i <= n;i++)
    {
        if(sh[i] == sh[i - 1])
            c++;
        else
        {
            fprintf(f2, "%lld", sh[i - 1]);
            fprintf(f2, " %d\n", c);
            c = 1;
        }
    }
    fprintf(f2, "%lld", sh[n]);
    fprintf(f2, " %d\n", c);
    return 0;
}
