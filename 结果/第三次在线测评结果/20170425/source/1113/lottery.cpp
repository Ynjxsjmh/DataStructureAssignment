#include <cstdio>
using namespace std;
//----------------------------------------
void get_in(FILE *in , int get_list[]);
void sort_list(int lis[]);
int compare(const int target[] , int now[]);
//----------------------------------------
int main()
{
    FILE *in , *out;
    in = fopen("lottery.in" , "r");
    out = fopen("lottery.out" , "w");
    int get_list[7] = {0};
    //----------------------------------------
    get_in(in , get_list);
    //----------------------------------------
    for (int i = 0 ; i < 7 ; i++)
    {
        fprintf(out , "%d " , get_list[i]);
    }
    fclose(in);
    fclose(out);
}
//----------------------------------------
void get_in(FILE *in , int get_list[])
{
    int num;
    int target[7];
    int now[7];
    int times;
    fscanf(in , "%d" , &num);
    for (int i = 0 ; i < 7 ; i++)
    {
        fscanf(in , "%d" , &target[i]);
    }
    sort_list(target);
    //----------------------------------------
    for (int j = 0 ; j < num ; j++)
    {
        for (int k = 0 ; k < 7 ; k++)
        {
            fscanf(in , "%d" , &now[k]);
        }
        sort_list(now);
        times = compare(target , now);
        switch (times)
        {
            case 7 : get_list[0]++;break;
            case 6 : get_list[1]++;break;
            case 5 : get_list[2]++;break;
            case 4 : get_list[3]++;break;
            case 3 : get_list[4]++;break;
            case 2 : get_list[5]++;break;
            case 1 : get_list[6]++;break;
            case 0 : break;
        }
    }
    //----------------------------------------
}
//----------------------------------------
void sort_list(int lis[])
{
    //printf("hi sort\n");
    bool flag = true;
    int temp;
    while (flag)
    {
        flag = false;
        for (int i = 0 ; i < 6 ; i++)
        {
            if (lis[i] > lis[i + 1])
            {
                temp = lis[i];
                lis[i] = lis[i + 1];
                lis[i + 1] = temp;
                flag = true;
            }
        }
    }
}
//----------------------------------------
int compare(const int target[] , int now[])
{
    //printf("hi\n");
    int times = 0 , t = 0 , n = 0;
    //----------------------------------------
    while (t < 7 && n < 7)
    {
        if (t < 7 && n < 7 && target[t] == now[n])
        {
            ++times;
            ++t;
            ++n;
        }
        while (target[t] < now[n] && t < 7 && n < 7)
        {
            ++t;
        }
        while (target[t] > now[n] && t < 7 && n < 7)
        {
            ++n;
        }
    }
    //----------------------------------------
    //printf("%d\n" , times);
    return times;
}
//----------------------------------------
