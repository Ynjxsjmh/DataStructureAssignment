#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    FILE *fp = fopen("circle.in","r");
    int n;
    fscanf(fp, "%d", &n);
    float *x, *y, *r;
    x = new float[n];
    y = new float[n];
    r = new float[n];
    int *m;
    int mm = 0;
    m = new int[n];
    for(int i = 0; i < n; i++)
    {
        m[i] = -1;
    }
    for(int i = 0; i < n; i++)
    {
        fscanf(fp, "%f", &x[i]);
        fscanf(fp, "%f", &y[i]);
        fscanf(fp, "%f", &r[i]);
    }
    fclose(fp);
    for(int i = 0; i < n; i++)
    {
        if(m[i] == -1)
        {
            m[i] = mm;
            mm++;
        }
        for(int j = i+1; j < n; j++)
        {
            if(sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) <= r[i] + r[j])
            {
                m[j] = m[i];
            }
        }
    }
    fp = fopen("circle.out", "w");
    fprintf(fp, "%d", mm);
    fclose(fp);
    delete[] x;
    delete[] y;
    delete[] r;
    delete[] m;
}
