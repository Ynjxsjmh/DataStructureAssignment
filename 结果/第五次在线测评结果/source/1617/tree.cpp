#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
typedef struct anode
{
        int name;
        int ver;
        int cost;
        int d;
        anode* link;
}node;

node* vert[1001]={NULL};
int vi[1001]={0};
int dept=0,ct=1;
int n;

void reset()
{
        memset(vi,0,sizeof(vi));
        printf("\n");
}

void visit(int x,int d)
{
        vi[x]=1;
        vert[x]->d=d;
        return;
}
void visit2(int x,int d)
{
        vi[x]=1;
        return;
}

int dep(int x)
{
        int i;
        queue<node*>Q;
        node* p=vert[x];
        visit(x,1);
        while(p)
        {
                Q.push(p);
                visit(p->ver,2);
                p=p->link;
        }

        while(!Q.empty())
        {

                p=Q.front();Q.pop();

                for(i=vert[p->ver]->d+1,p=vert[p->ver];p;p=p->link)
                {

                        if(!vi[p->ver])
                        {
                                Q.push(p);
                                visit(p->ver,i);
                        }
                        //i=vert[p->ver]->d+1
                }
        }
        return i-1;
}
int b(int x)
{
        int bb=0;
        int *b=(int*)malloc(sizeof(int)*x);
        for(int i=0;i<x;i++)
        {
                b[i]=0;
        }
        for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                        if(vert[j]->d==i)
                                b[i-1]++;
        for(int i=0;i<x;i++)
        {
                if(b[i]>bb)
                        bb=b[i];
        }
        return bb;
}

int find(int x,int y)
{
        int *dis=(int*)malloc(sizeof(int)*x);
        for(int i=0;i<x;i++)
        {
                dis[i]=0;
        }
        queue<node*>Q;
        node* p=vert[x];
        vi[x]=1;
        while(p)
        {
                Q.push(p);
                visit(p->ver);
                p=p->link;
        }
        while(!Q.empty())
        {
                p=Q.front();Q.pop();

                for(p=vert[p->ver];p;p=p->link)
                {
                        if(!vi[p->ver])
                        {
                                Q.push(p);
                                visit(p->ver);
                        }
                }
        }
        return dis[v];
}
int main()
{
        freopen("tree.in","r",stdin);
        freopen("tree.out","w",stdout);

        int x,y;
        scanf("%d",&n);
        node* p;
        for(int i=0;i<n-1;i++)
        {
                node* t=(node*)malloc(sizeof(node));
                scanf("%d%d",&x,&y);
                t->cost=1;
                t->ver=y;
                t->name=x;
                t->link=NULL;
                if(vert[x])
                {
                        t->link=vert[x]->link;
                        vert[x]->link=t;
                }
                else
                        vert[x]=t;
                t=(node*)malloc(sizeof(node));
                t->cost=2;
                t->ver=x;
                t->name=y;
                t->link=NULL;
                if(vert[y])
                {
                        t->link=vert[y]->link;
                        vert[y]->link=t;
                }
                else
                        vert[y]=t;
        }
        int d=dep(1);
        printf("%d\n",d);
        printf("%d\n",b(d));
        reset();

}
