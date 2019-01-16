#include<stdio.h>
#include<queue>
using namespace std;
int vis[100005];
int main()
{
    int n,k;
    FILE *fp1,*fp2;
    fp1=fopen("catchcow.in","r");
    fp2=fopen("catchcow.out","w");
    fscanf(fp1,"%d%d",&n,&k);
    queue<int> q;
    q.push(n);
    int x=0;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        if(x==k) break;
        if(x>0&&!vis[x-1])
        {
            q.push(x-1);
            vis[x-1]=vis[x]+1;
        }
        if(x<k&&!vis[x+1])
        {
            q.push(x+1);
            vis[x+1]=vis[x]+1;
        }
        if(x*2<100000&&!vis[x*2])
        {
            q.push(x*2);
            vis[x*2]=vis[x]+1;
        }
    }
    printf("%d",vis[x]);
    fprintf(fp2,"%d",vis[x]);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
