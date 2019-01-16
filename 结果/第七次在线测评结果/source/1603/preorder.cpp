#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
char s1[20], s2[20];
FILE *f1, *f2;
void po(int l, int r, int l1, int r1)
{
    fprintf(f2, "%c", s2[r1]);
    int p;
    for(p = l;p <= r;p++)
    {
        if(s1[p] == s2[r1])
            break;
    }
    if(p > l)
        po(l, p - 1, l1, l1 + p - 1 - l);
    if(p < r)
        po(p + 1, r, l1 + p - l, r1 - 1);
}
int main()
{
    f1 = fopen("preorder.in", "r");
    f2 = fopen("preorder.out", "w");
    fscanf(f1, "%s %s", s1, s2);
    int le = strlen(s1);
    po(0, le - 1, 0, le - 1);
    fprintf(f2, "\n");
    return 0;
}
