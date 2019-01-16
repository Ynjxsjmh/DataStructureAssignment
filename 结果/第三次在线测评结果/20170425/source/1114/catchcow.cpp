#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    queue<int> q,p;
    int n,k;
    FILE *fp = fopen("catchcow.in", "r");
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &k);
    fclose(fp);
    q.push(n);
    int i;
    for(i = 0;;i++)
    {
        int tem;
        while(!q.empty())
        {
            p.push(q.front());
            q.pop();
        }
        while(!p.empty())
        {
            tem = p.front();
            p.pop();
            if(tem == k)
                break;
            else
            {
                q.push(tem + 1);
                q.push(tem - 1);
                q.push(tem * 2);
                printf("a");
            }
        }
        if(tem == k)
            break;
    }
    printf("%d", i);
    FILE *pp = fopen("catchcow.out","w");
    fprintf(pp,"%d", i);
    fclose(pp);

}
