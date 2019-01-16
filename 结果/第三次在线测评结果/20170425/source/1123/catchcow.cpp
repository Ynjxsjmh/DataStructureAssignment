#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;

struct Node
{
    int x;
    int time;
    Node(int x1,int time1):x(x1),time(time1){}
};

int bfs(int N,int K)
{
    int stepArr[2]={-1,1};
    int vis[100005];
    memset(vis,0,sizeof(vis));
    queue<Node> que;
    Node node(N,0);
	que.push(node);
    while(!que.empty())
    {
        node=que.front();
        que.pop();
        if(node.x == K)
			return node.time;
        vis[node.x]=1;
        for(int i=0;i<2;i++)
        {
            int x1=node.x+stepArr[i];
            if(x1>=0 && x1<=100000 && vis[x1]==0)
            {
                Node next(x1,node.time+1);
				que.push(next);
            }
        }
        int x2=node.x*2;
        if(x2>=0 && x2 <=100000 && vis[x2]==0)
        {
            Node next(x2,node.time+1);
            que.push(next);
        }
    }
    return -1;
}

int main()
{
    int N,K;
    freopen("catchcow.in","r",stdin);
    freopen("catchcow.out","w",stdout);
    scanf("%d%d",&N,&K);
    printf("%d",bfs(N,K));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
