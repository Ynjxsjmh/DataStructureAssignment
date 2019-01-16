
#include<stdio.h>
#include<stdlib.h>
typedef struct tnode{
    int order;//以char为例
    struct tnode*left,*right;
}Tnode;
Tnode*T[100];
typedef struct{
    Tnode*root;
}Binarytree;
//求二叉树的深度
int GetDepth(Tnode *pRoot)
{
   if (pRoot == NULL)
    {
      return 0;
   }

    //  int nLeftLength = GetDepth(pRoot->m_left);
    //  int nRigthLength = GetDepth(pRoot->m_right);
    //  return nLeftLength > nRigthLength ? (nLeftLength + 1) : (nRigthLength + 1);

    return GetDepth(pRoot->left) > GetDepth(pRoot->right) ?
        (GetDepth(pRoot->left) + 1) : (GetDepth(pRoot->right) + 1);
}


void breadth(Tnode*t)
{
    int a[100]={0};
int i=0;
 if(t!=NULL)
 {
  if(i==0)
  {
   a[0]=1;
   i++;
   if(t->left!=NULL) a[i]++;
   if(t->right!=NULL) a[i]++;

  }
  else{
   i++;
   if(t->left!=NULL) a[i]++;
   if(t->right!=NULL) a[i]++;
  }
  breadth(t->left);
  i--;
  breadth(t->right);
 }
 }
int max(int a[])
{

}

/*Tnode* preorder_recursion(Tnode*t,int u)
{
    Tnode*re1,*re2,*re3,*re4;
    if(t==NULL)
        re1=NULL;
    if(u==t->order)
         re2=t;
    re3=preorder(t->left);
    re4=preorder(t->right);
    if(re1!=NULL)
        return re1;
    if(re2!=NULL)
        return re2;
    if(re3!=NULL)
        return re2;
    if(re4!=NULL)
        return re4;
    return NULL;
}*/
int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    int n;
    Tnode*w,*m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {T[i]->order=i+1;
        T[i]->right=NULL;
        T[i]->left=NULL;
        }
    Binarytree*bt=(Binarytree*)malloc(sizeof(Binarytree));
    bt->root=T[0];
    int i1,i2;
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&i1,&i2);
        if(T[i1-1]->left==NULL)
        T[i1-1]->left=T[i2-1];
        else
            T[i1-1]->right=T[i2-1];

    }
    printf("%d",GetDepth(bt->root));
    printf("%d",breadth(bt->root));
    int s1,s2;
    scanf("%d%d",&s1,&s2);
    cal_dist(s1,s2);
   // fclose(stdin);
    //fclose(stdout);
return 0;
}
