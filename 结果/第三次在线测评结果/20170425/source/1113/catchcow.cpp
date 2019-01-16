#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxlen = 300000;
//----------------------------------------
int get_step(int N , int K , int visited[]);
//----------------------------------------
int main()
{
    int N , K , step;
    int visited[maxlen] = {0};
    FILE *in , *out;
    in = fopen("catchcow.in" , "r");
    out = fopen("catchcow.out" , "w");
    fscanf(in , "%d%d" , &N , &K);
    //----------------------------------------
    step = get_step(N , K , visited);
    //----------------------------------------
    fprintf(out , "%d" , step);
    fclose(in);
    fclose(out);
}
//----------------------------------------
int get_step(int N , int K , int visited[])
{
    if (N >= K)
    {
        return N-K;
    }
    //----------------------------------------
    queue<int> qu;
    qu.push(N);
    visited[N] = 1;
    int temp;
    while (!qu.empty())
    {
        temp = qu.front();
        qu.pop();
        if (temp == K)
        {
            return visited[temp] - 1;
        }
        if (temp + 1 < maxlen && visited[temp + 1] == 0)
        {
            qu.push(temp + 1);
            visited[temp + 1] = visited[temp] + 1;
        }
        if (temp - 1 > 0 && temp - 1 < maxlen && visited[temp - 1] == 0)
        {
            qu.push(temp - 1);
            visited [temp - 1] = visited[temp] + 1;
        }
        if (temp * 2 < maxlen && visited[temp * 2] == 0)
        {
            qu.push(temp * 2);
            visited[temp * 2] = visited[temp] + 1;
        }
    }
}
//----------------------------------------
