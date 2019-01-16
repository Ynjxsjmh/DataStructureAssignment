#include<stdio.h>
#define M 100100
int a[M] = {}, Q[M];
int aim, head = 0, tail = -1;
void pushh(int d){Q[++tail] = d;}
int popp(void){return Q[head++];}
int run(int s, int t)
{
    if(s > aim)
    {
        if(a[aim] == 0 || a[aim] > s - aim + t)
        a[aim] = s - aim + t;
        return 0;
    }
    if(s + 1 == aim || s * 2 == aim)
    {
        a[aim] = t + 1;
        return 0;
    }
    if(a[s + 1] == 0)
    {
        a[s + 1] = t + 1;
        pushh(s + 1);
    }
    if(a[s - 1] == 0)
    {
        a[s - 1] = t + 1;
        pushh(s - 1);
    }
    if(2 * s < M)
    {
        a[s * 2] = t + 1;
        pushh(s * 2);
    }
    return 0;
}
int main(void)
{
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    int start;
    scanf("%d%d", &start, &aim);
    run(start, 0);
    while(head < tail)
    {
        int s = popp();
        run(s, a[s]);
    }
    printf("%d", a[aim]);
    return 0;
}
