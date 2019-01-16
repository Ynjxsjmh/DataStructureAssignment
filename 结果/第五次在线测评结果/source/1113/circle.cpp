#include <iostream>
#include <cstdio>
#include <cmath>
//----------------------------------------
struct acircle
{
    int x;
    int y;
    int r;
    bool attached;
    //----------------------------------------
    acircle()
    {
        x = 0;
        y = 0;
        r = 0;
        attached = false;
    }
};
//----------------------------------------
using namespace std;
//----------------------------------------
int main()
{
    FILE *in , *out;
    in = fopen("circle.in" , "r");
    out = fopen("circle.out" , "w");
    //----------------------------------------
    int n;
    acircle A[7000];
    double dist;
    fscanf(in , "%d" , &n);
    const int N = n;
    for (int i = 0 ; i < n ; i++)
    {
        fscanf(in , "%d%d%d" , &(A[i].x) , &(A[i].y) , &(A[i].r));
        //printf("%d%d%d" , A[i].x , A[i].y , A[i].r);
    }
    for (int j = 0 ; j < N-1 ; j++)
    {
        A[j].attached = true;
        for (int p = j + 1 ; p < N ; p++)
        {
            dist = sqrt((A[p].x - A[j].x) * (A[p].x - A[j].x) + (A[p].y - A[j].y) * (A[p].y - A[j].y));
            if (!A[p].attached && (A[p].r + A[j].r) - dist > 1e-10 )
            {
                n--;
                A[p].attached = true;
            }
        }
    }
    fprintf(out , "%d" , n);
    //----------------------------------------
    fclose(in);
    fclose(out);
    cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
