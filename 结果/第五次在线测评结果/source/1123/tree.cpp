#include<iostream>
#include<cstdio>
#define max(a,b) (a>b?a:b)
#define N 120
using namespace std;

struct TreeNode{
    int data;
    int level;
    TreeNode*left,*right,*father;
    TreeNode(int item=0,TreeNode*left_input=NULL,TreeNode*right_input=NULL,TreeNode*father_input=NULL):level(0),data(item),left(left_input),right(right_input),father(father_input){}
};

class tree{
private:
    TreeNode*t;
public:
    tree(int n=0){t=new TreeNode(1);}
    TreeNode*Find(TreeNode*t,const int&item)//搜索符合数据域条件的结点
    {
        TreeNode* temp;
        if (t == NULL)
        {
            return NULL;
        }
        if (t->data == item)
        {
            return t;
        }
        return (temp = Find(t->left, item)) != NULL ? temp : Find(t->right, item);
    }
    void add(TreeNode*p,TreeNode*item)
    {
        item->level=p->level;
        if(p->left==NULL)
        {
            p->left=item;
        }
        else if(p->right==NULL)
        {
            p->right=item;
        }
        else return;
    }
    TreeNode*getT(){return t;}
    int depth(TreeNode*t) const//先根遍历
    {
        if(t->left==NULL&&t->right==NULL)
        {
            return t->level;
        }
        if (t != NULL)
        {
            return max(depth(t->left),depth(t->right));
        }
    }
};

int main()
{
    int i,n,x,y,u,v;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    tree atree(n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);//x为父节点，y为子节点
        TreeNode*temp=new TreeNode(y,NULL,NULL,atree.Find(atree.getT(),x));
        atree.add(atree.Find(atree.getT(),x),temp);
    }
    scanf("%d%d",&u,&v);
    printf("%d\n",atree.depth(atree.getT()));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
