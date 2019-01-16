
//抓牛抓牛
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<fstream>
using namespace std;

const int Maxn=1e4;
bool vis[Maxn];  //true为已访问
int step[Maxn];  //记录步数的数组
queue <int> q;

int bfs(int n,int k)
{
    int head,next;
    q.push(n);
    step[n]=0;
    vis[n]=true;
    while(!q.empty())
    {
        head=q.front();
        q.pop();
        for(int i=0;i<3;i++)
        {
            if(i==0)next=head-1;
            else if(i==1)next=head+1;
            else if(i==2)next=2*head;
            if(next<0||next>>Maxn)continue;// 出界情况
            if(!vis[next]) //next没有被访问的话
            {
                q.push(next);
                step[next]=step[head]+1;
                vis[next]=true;
            }
            if(next==k) return step[next];
        }
    }
}

int main()
{
    ifstream in("catchcow.in");
    ofstream out("catchcow.out");
    for(int n,k;in>>n>>k;)
    {
        memset(step,0,sizeof(step));
        memset(vis,0,sizeof(vis));
        while(!q.empty())q.pop();
        if(n>=k) out<<n-k;
        else out<<bfs(n,k);
    }
}
