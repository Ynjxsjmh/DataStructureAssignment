#include<iostream>
#include<queue>
using namespace std;

struct BTNode
{
	char data;
	BTNode *left,*right;
};

class BTree
{
public:
	BTNode *root;
	BTree(){root=new BTNode;root->data='1';root->left=NULL;root->right=NULL;}//根结点为1
	void create(BTNode *t);
	void insert(BTNode *t,char item);
	BTNode * find(BTNode *t,char item);
	void levelorder(BTNode *t);
	int height(BTNode *t);
	int calwidth(BTNode *t);
};

void BTree::insert(BTNode *t,char item)
{
	BTNode *p;
	p=new BTNode;
	p->data=item;
	p->left=NULL;
	p->right=NULL;
	if(t->left==NULL)
	{
		t->left=p;
	}
	else
	{
		t->right=p;
	}
}

BTNode * BTree::find(BTNode *t,char item)//输入参数t为根节点 
{
	BTNode *p,*q;
	if(t==NULL)
		return NULL;
	if(t->data==item)
	{
		q=t;
		return q;
	}
	p=find(t->left,item);
	if(p!=NULL)//如果不空，即为所求解，如果空，则向右搜索
	{
		q=p;
		return q;
	}
	q=find(t->right,item);
	return q;
}

void BTree::create(BTNode *t)//输入参数t为根节点
{
	int n;
	scanf("%d",&n);
	getchar();//!!!!!!!!!!!!!!!
	char c1,c2;//c1 c2 
	for(int i=0;i<n-1;i++)
	{
		scanf("%c %c",&c1,&c2);
		getchar();
		insert(find(t,c1),c2); 
	}
	scanf("%c %c",&c1,&c2);
	getchar();
}

void BTree::levelorder(BTNode *t)
{
	queue<BTNode *>q;
	BTNode *p=t;
	if(p!=NULL)
		q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p->data<<endl;
		if(p->left!=NULL)
			q.push(p->left);
		if(p->right!=NULL)
			q.push(p->right);
	}
}

int BTree::height(BTNode *t)
{
	int l,r;
	if(t==NULL)
  		return(0);
	else
	{
	   l=height(t->left);
	   r=height(t->right);
	   if(l>r)
	   		return l+1;
		else
			return r+1;
	}
}

int BTree::calwidth(BTNode *t)
{
	int w[100];
	int max=0;
	int f=1;
	if(t)
	{
		if(f==1)
		{
			w[f]++;
			f++;
			if(t->left)
				w[f]++;
			if(t->right)
				w[f]++;
		}
		else
		{
			f++;
			if(t->left)
				w[f]++;
			if(t->right)
				w[f]++;
		}
		if(max<w[f])
			max=w[f];
		calwidth(t->left);
		f--;
		calwidth(t->right);
	}
	return max;
}

int main()
{
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	BTree tree;
	tree.create(tree.root);
	printf("%d\n%d\n2",tree.height(tree.root),tree.calwidth(tree.root));
	return 0;
}
