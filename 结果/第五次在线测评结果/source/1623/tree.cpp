#include <stdio.h>
int n,x,y,g[123][123],d[123],ge[123],visited[123],que[123],jl[123],front,rear;
void bfs()
{
    d[1]=1;
    visited[1]=1;
    front=rear=0;
    que[rear++]=1;
    while(front!=rear)
    {
        x=que[front++];
        for(y=1;y<=n;y++)
            if(g[x][y]==1&&visited[y]==0)
            {
                visited[y]=1;
                d[y]=d[x]+1;
                que[rear++]=y;
            }
    }
}
int juli(int u, int v)
{
    int i;
    for(i=1;i<=n;i++)
        visited[i]=0;
    front=rear=0;
    visited[u]=1;
    jl[v]=0;
    que[rear++]=u;
    while(front!=rear)
    {
        x=que[front++];
        for(y=1;y<=n;y++)
            if(g[x][y]==1&&visited[y]==0)
            {
                visited[y] = 1;
                if(d[y]>d[x])
                    jl[y]=jl[x]+1;
                else
                    jl[y]=jl[x]+2;
                que[rear++]=y;
            }
    }
    return jl[v];
}
main()
{
    int i;
    int max=0;
    int width=0;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        g[x][y]=1;
        g[y][x]=1;
    }
    bfs();
    for(i=1;i<=n;i++)
        if(d[i]>max)
            max=d[i];
    for(i=1;i<=n;i++)
        ge[d[i]]++;
    for(i=1;i<=max;i++)
        if(ge[i]>width)
        width=ge[i];
    scanf("%d %d",&x,&y);
    printf("%d\n%d\n%d\n",max,width,juli(x,y));
    fclose(stdin);
    fclose(stdout);
}
