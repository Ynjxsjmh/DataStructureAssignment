#include <iostream>
#include <stdio.h>
#include <algorithm>
#define N 50000
using namespace std;
bool compare(int a, int b)
{
    return a<b;
}
int main()
{
    long long a[N];
    int number;
    FILE *fp = fopen("count.in","r");
    fscanf(fp, "%d", &number);
    for(int i = 0; i < number; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    sort(a, a + number, compare);
    int start = 0;
    fp = fopen("count.out", "w");
    for(int i = start; i < number; i = start)
    {
        fprintf(fp,"%d ", a[i]);
        int j;
        for(j = i+1; a[j] == a[i]; j++);
        start = j;
        fprintf(fp, "%d\n", j-i);
    }
    fclose(fp);
}
