#include <iostream>
#include <cstdio>
#include <stack>
//----------------------------------------
int get_depth(int n , int treemap[101][101]);
//----------------------------------------
int get_wide(int n , int treemap[101][101]);
//----------------------------------------
int get_dist(int n , int treemap[101][101] , int u , int v);
//----------------------------------------
using namespace std;
//----------------------------------------
int main()
{
	FILE *in , *out;
	in = fopen("tree.in" , "r");
	out = fopen("tree.out" , "w");
	//----------------------------------------
	int n , u , v;
	int treemap[101][101] = {0};
	fscanf(in , "%d" , &n);
	for (int i = 0 ; i < n - 1 ; i++)
	{
		fscanf(in , "%d%d" , &u , &v);
		treemap[u][v] = 1;
		treemap[v][u] = 1;
	}
	fscanf(in , "%d%d" , &u , &v);
	int wide = 0;
	int depth = 0;
	int dist = 0;
	wide = get_wide(n , treemap);
	//depth = get_depth(n , treemap);
	dist = get_dist(n , treemap , u , v);
	fprintf(out , "%d\n%d\n%d" , depth , wide , dist);
	//----------------------------------------
	fclose(in);
	fclose(out);
    cout << "Hello world!" << endl;
    return 0;
}
//----------------------------------------
int get_depth(int n , int treemap[101][101])
{
    stack<int> former , later;
    int d = 0;
    int temp;
    former.push(1);
    int i;
    while (true)
    {
        if (former.empty() && later.empty())
        {
            break;
        }
        if (former.empty())
        {
            d++;
            while (!later.empty())
            {
                temp = later.top();
                later.pop();
                for ( i = 1 ; i <= n ; i++)
                {
                    if(treemap[temp][i])
                    {
                        former.push(i);
                    }
                }
            }
        }
        if (later.empty())
        {
            d++;
            while (!former.empty())
            {
                temp = former.top();
                former.pop();
                for ( i = 1 ; i <= n ; i++)
                {
                    if(treemap[temp][i])
                    {
                        later.push(i);
                    }
                }
            }
        }
    }
	return d;
}
//----------------------------------------
int get_wide(int n , int treemap[101][101])
{
	return 0;
}
//----------------------------------------
int get_dist(int n , int treemap[101][101] , int u , int v)
{
    int prev1  = 0, prev2 = 0;
    int after1 = u , after2 = v;
    int coun1 = 0 , coun2 = 0;
    int i;
    while(prev1 != 1)
    {
        for (i = 1 ; i <= n ; i++)
        {
            if (treemap[i][after1])
            {
                prev1 = i;
                after1 = i;
                coun1++;
                break;
            }
        }
    }
    while(prev2 != 1)
    {
        for (i = 1 ; i <= n ; i++)
        {
            if (treemap[i][after2])
            {
                prev2 = i;
                after2 = i;
                coun2++;
                break;
            }
        }
    }
	return coun1 * 2 + coun2;
}
//----------------------------------------
