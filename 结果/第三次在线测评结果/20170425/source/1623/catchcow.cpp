#include"stdio.h"
#define N 100001
int n,k,s;
int visited[N],time[N];
int que[N],a,b;
int now;
int bfs()
{
    a=b=0;
    que[b]=n;
    b++;
    visited[n]=1;
    time[n]=0;
    while(a!=b)
    {
        now=que[a]+1;
        if(now>=0&&now<=100000&&visited[now]==0)
        {
            visited[now]=1;
            time[now]=time[que[a]]+1;
            if(now==k)
                return time[now];
            que[b]=now;
            b++;
        }
        now=que[a]-1;
        if(now>=0&&now<=100000&&visited[now]==0)
        {
            visited[now]=1;
            time[now]=time[que[a]]+1;
            if(now==k)
                return time[now];
            que[b]=now;
            b++;
        }
        now=que[a]*2;
        if(now>=0 && now<=100000 && visited[now]==0)
        {
            visited[now]=1;
            time[now]=time[que[a]]+1;
            if(now==k)
                return time[now];
            que[b]=now;
            b++;
        }
        a++;
    }
}
main()
{
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    scanf("%d%d",&n,&k);
    s=bfs();
    printf("%d\n",s);
    fclose(stdin);
    fclose(stdout);
}
