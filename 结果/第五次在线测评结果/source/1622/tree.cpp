#include<stdio.h>
#include<malloc.h>
typedef struct n  //树结点的结构体
{
     struct n*left;
     struct n*right;
     char data;
} tnode;
tnode *queue[10000];
int rear,front=0;
tnode* find(tnode*t,int ch)//查找结点
 {
     if(t==NULL){

           return t;
     }
     else if(t->data==ch)
     {
          ;
          return(t);
     }
     else
     {
          tnode*lp;
         lp=find(t->left,ch);
         if(lp!=NULL)
         {

              return lp;
         }
         else
         {
              tnode*rp;
              rp=find(t->right,ch);
              return rp;
         }
     }
 }
int deep(tnode*r)
{
    int lef,rig;
    if(r==NULL)
    {
        return 0;
    }
    lef=deep(r->left);
    rig=deep(r->right);
    if(lef>rig)
        return lef+1;
    else
        return rig+1;
}
int wid(tnode*t)
{
    int noww=0,lw=0,nw=0;
    tnode*point;
    if(t==NULL)
        return NULL;
    else
    {
        queue[rear]=t;
        rear++;
        lw=1;
        noww=1;
        while(front!=rear)
        {
            while(lw!=0)
              {
                 point=queue[front];
                 front++;
                if(point->left!=NULL)
                {
                    queue[rear]=point->left;
                    rear++;
                }
                 if(point->right!=NULL)
                {
                    queue[rear]=point->right;
                    rear++;
                }
                    lw--;
            }
            noww=rear-front;
            if(noww>lw)
                nw=noww;
            else
                nw=lw;
            lw=noww;
        }
        return nw;
    }

}
int rootlen(tnode*t,tnode *p)
{
     int noww=0,lw=0,nw=0;
     int time=0;
    tnode*point;
    if(t==NULL)
        return NULL;
    else
    {
        queue[rear]=t;
        rear++;
        lw=1;
        noww=1;
        time=0;
        while(front!=rear)
        {
            while(lw!=0)
              {
                 point=queue[front];
                 front++;
                if(point->left!=NULL)
                {
                    if(point->left==p)
                        return time+1;
                    queue[rear]=point->left;
                    rear++;
                }
                 if(point->right!=NULL)
                {
                    if(point->right==p)
                        return time+1;
                    queue[rear]=point->right;
                    rear++;
                }
                    lw--;
            }
            time++;
            noww=rear-front;

        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    tnode*r,*p,*q;
    int depth,width,lenth;
    int n,i,j,x,y,m,v;
    scanf("%d",&n);
      r=(tnode*)malloc(sizeof(tnode));
        r->data=1;
        r->left=NULL;
        r->right=NULL;

    for(i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        p=(tnode*)malloc(sizeof(tnode));
        p->data=x;
        p->left=NULL;
        p->right=NULL;
        q=find(r,x);
        if(q!=NULL)
        {
            if(q->left==NULL)
                        q->left=p;
            else
                q->right=p;
        }

    }
    depth=deep(r);
    width=wid(r);
    scanf("%d%d",&x,&y);
    p=find(r,x);
    q=find(r,y);
    m=rootlen(r,p);
    v=rootlen(r,q);
    lenth=3*m+v;
    printf("%d\n",depth);
     printf("%d\n",width);
      printf("%d\n",lenth);
      return 0;
}
