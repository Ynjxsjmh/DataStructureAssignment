#include<stdio.h>
#include<string.h>
#define key 1
char a[13], b[13];
int R[13], L[13];
int cut(int x1, int y1, int x2, int y2)
{
    if(key)printf("\nx1:%d y1:%d x2:%d y2:%d", x1, y1, x2, y2);
    if(x1 > y1)
        return -1;
    int i = x2, len, k;
    while(b[i] != a[y1])
        i++;              //find root
    len = i - x2 ;      // left length
    L[y1] = cut(x1, x1 + len - 1, x2, i - 1);
    R[y1] = cut(x1 + len, y1 - 1, i + 1, y2);
    if(key)printf("\n a:%c L:%d R:%d", a[y1], L[y1], R[y1]);
    return x1;
}
void outt(int i)
{
    printf("%c", a[i]);
    if(L[i] != -1)
        outt(L[i]);
    if(R[i] != -1)
        outt(R[i]);
}
int main(void)
{
   freopen("preorder.in", "r", stdin);
    freopen("preorder.out", "w", stdout);
    for(int i = 0; i < 13; i++)
    {
        R[i] = -1;
        L[i] = -1;
    }
    scanf("%s%s", b, a);
    cut(0, strlen(a) - 1, 0, strlen(b) - 1);
    outt(strlen(a) - 1);
    //printf("%s %s", a, b);
    return 0;
}
