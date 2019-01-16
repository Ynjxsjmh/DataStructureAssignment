#include<stdio.h>
#include<string.h>
struct point{
    int data;
    int num;
}queue[100005];
int N,K;
int visited[100005];
int bfs(int a)
{
    memset(visited,0,sizeof(visited));
    struct point temp;
    int head,tail;
    visited[a]=1;
    head=0;
    tail=0;
    queue[tail].data=a;
    queue[tail++].num=0;

    while(head<tail)
    {
        temp=queue[head++];
        if(temp.data+1>0&&temp.data+1<=100005&&!visited[temp.data+1])
        {
            queue[tail].data=temp.data+1;
            queue[tail++].num=temp.num+1;

            visited[temp.num+1]=1;
            if(temp.data+1==K)
                return temp.num+1;


        }


            if(temp.data-1>0&&temp.data-1<=100005&&!visited[temp.data-1])
            {
                queue[tail].data=temp.data-1;
                queue[tail].num=temp.num+1;
                tail++;

                visited[temp.data-1]=1;
                if(temp.data-1==K)
                return temp.num+1;
            }



    if(temp.data*2>0&&temp.data*2<=100005&&!visited[temp.data*2])
        {
            queue[tail].data=temp.data*2;
            queue[tail++].num=temp.num+1;


            visited[temp.data*2]=1;
            if(temp.data*2==K)
            return temp.num+1;
        }
    }
return 0;
}
int main(){
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    scanf("%d%d",&N,&K);
    if(N>=K)
        printf("%d\n",N-K);
    else
        printf("%d\n",bfs(N));
        fclose(stdin);
        fclose(stdout);
    return 0;
}

