
#include<algorithm>
#include<stdio.h>
#define N 7
using namespace std;
bool cmp(int a, int b)
{
     return a>b;
}
int main()
{
    int a[N],example;
    FILE *fp = fopen("lottery.in", "r");
    fscanf(fp, "%d", &example);
    for(int i = 0; i < N; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
    sort(a,a+7,cmp);
    int r[N] = {0, 0, 0, 0, 0, 0, 0};
    for(int e = 0; e < example; e++)
    {
        int b[N];
        int n = 7;
        for(int i = 0; i < N; i++)
        {
            fscanf(fp, "%d", &b[i]);
        }
        sort(b,b+7,cmp);
        for(int i = 0, j = 0; i < N && j < N;)
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
                n--;
            }
            else if(a[i] > b[j])
            {
                i++;
            }
            else if(a[i] < b[j])
            {
                j++;
            }
        }
        if(n != 7)
            r[n]++;
    }
    FILE *ffp = fopen("lottery.out","w");
    for(int i = 0; i < N-1; i++)
    {
        fprintf(ffp,"%d ", r[i]);
    }
    fprintf(ffp,"%d", r[N-1]);
    fclose(fp);
    fclose(ffp);

}
