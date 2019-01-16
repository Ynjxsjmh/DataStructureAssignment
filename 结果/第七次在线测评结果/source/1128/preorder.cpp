#include <stdio.h>
#include <iostream>
using namespace std;
char mid[11];
char aft[11];
struct node
{
    char ch;//='#';
    struct node *left;//=NULL;
    struct node *right;//=NULL;
    node()
    {
        ch='#';
        left=NULL;
        right=NULL;
    }
};
void deal(int a,int b,int c,int d,node*n)
{
    int x,y,z;
    node *p;
    node *q;
    char cur=aft[d];
    for(x=a;x<=b;x++)
        if(mid[x]==cur)
            break;
    n->ch=cur;
    if(x==a+1)
    {
        p=new node;
        n->left=p;
        p->ch=mid[a];
    }
    else if(x>a+1)
    {
        p=new node;
        n->left=p;
        deal(a,x-1,c,c+x-a-1,p);
    }
    if(x==b-1)
    {
        q=new node;
        n->right=q;
        q->ch=mid[b];
    }
    else if(x<b-1)
    {
        q=new node;
        n->right=q;
        deal(x+1,b,d-(b-x),d-1,q);
    }
}
void pre_d(node*p)
{
    if(p==NULL)
        return;
    printf("%c",p->ch);
    pre_d(p->left);
    pre_d(p->right);
}
int main()
{
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
    int i;
    node root;
    scanf("%s",mid);
    scanf("%s",aft);
    for(i=0;mid[i];i++);
    i--;
    deal(0,i,0,i,&root);
    pre_d(&root);
    return 0;
}
