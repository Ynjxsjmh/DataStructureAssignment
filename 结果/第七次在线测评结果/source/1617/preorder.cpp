#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct atree
{
        char data;
        struct atree *l,*r;
}tree;

void build(char *ino,char *pos,int len,tree **root);
void preo(tree *p);

int main()
{
        freopen("preorder.in","r",stdin);
        freopen("preorder.out","w",stdout);
        char pos[27]={'\0'},ino[27]={'\0'};
        scanf("%s%s",ino,pos);
        {
                tree *root;
                build(ino,pos,strlen(pos),&root);
                preo(root);
                //printf("\n");
        }
}

void build(char *ino,char *pos,int len,tree **root)
{
        if(len==0)
                return;
        tree *p=(tree*)malloc(sizeof(tree));
        char z=pos[len-1];
        *root=p;
        p->data=z;
        p->l=NULL;
        p->r=NULL;
        /***在中根序列中找到跟的位置***/
        char *tr=ino;
        int llen=0;
        for(;*tr!=z;llen++,tr++);
        /***确定左子树的信息***/
        build(ino,pos,llen,&(p->l));
        build(ino+llen+1,pos+llen,len-llen-1,&(p->r));
}

void preo(tree *p)
{
        if(p!=NULL)
        {
                printf("%c",p->data);
                preo(p->l);
                preo(p->r);
        }
}
