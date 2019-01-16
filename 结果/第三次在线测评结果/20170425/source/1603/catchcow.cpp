#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int catchcow(int t, int a, int b)
{
    if(a >= b)
        return a - b + t;
    if(a >= b * 3 / 4)
        return b - a + t;
    if(b % 2 == 0)
        return catchcow(t + 1, a, b / 2);
    return min(catchcow(t + 1, a, b + 1), catchcow(t + 1, a, b - 1));
}
int main()
{
    FILE* f1;
    FILE* f2;
    f1 = fopen("catchcow.in", "r");
    f2 = fopen("catchcow.out", "w");
    int a, b;
    fscanf(f1, "%d %d", &a, &b);
    int c = catchcow(0, a, b);
    fprintf(f2, "%d\n", c);
    return 0;
}
