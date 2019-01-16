#include<cstdio>
#include<cstring>
#define N 10

int vis[N+2];
char inOrder[N+1];
char postOrder[N+1];

struct treeNode
{
    char data;
    treeNode*left,*right;
    treeNode(char da=NULL,treeNode*le=NULL,treeNode*ri=NULL){data=da;left=le;right=ri;}
};

int pos(char*p,char ch)
{
    for(int i=0;i<strlen(p);i++)
    {
        if(p[i]==ch)
            return i;
    }
    return -1;
}

void dfs(treeNode*t)
{
    if(t==NULL)
        return;
    if(!vis[pos(inOrder,t->data)+1])
    {
        t->right=new treeNode(inOrder[pos(inOrder,t->data)+1]);
    }
    if(!vis[pos(inOrder,t->data)-1])
    {
        t->left=new treeNode(inOrder[pos(inOrder,t->data)-1]);
    }
    dfs(t->left);
    dfs(t->right);
}

void pre(treeNode*t)
{
    if(t==NULL)
        return;
    printf("%c",t->data);
    pre(t->left);
    pre(t->right);
}

int main()
{
    freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);

    treeNode*root;
    int len;

    scanf("%s%s",inOrder,postOrder);

    len=strlen(inOrder);
    root=new treeNode(postOrder[len-1]);

    for(int i=pos(inOrder,root->data)-1;i>=0;i--)
    {
        treeNode*cur=root;
        if(inOrder[i+1]==cur->data)
        {
            cur->left=new treeNode(inOrder[i]);
            cur=cur->left;
            vis[i]=1;
        }
    }
    for(int i=pos(inOrder,root->data)+1;i<len;i++)
    {
        treeNode*cur=root;
        if(inOrder[i-1]==cur->data)
        {
            cur->right=new treeNode(inOrder[i]);
            cur=cur->right;
            vis[i]=1;
        }
    }
    for(int i=0;i<N;i++)
    {
        dfs(root);
    }
    pre(root);
   // fclose(stdin);
    //fclose(stdout);
    return 0;
}
