#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#define MaxSize 20
using namespace std;
typedef struct Node
{
	struct Node*left, *right;
	int data;
}TreeNode;
TreeNode* CreateTree(int n)//创建树
{
	TreeNode*p, *q, *root;
	int parent, child;
	TreeNode* queue[MaxSize];
	int front = 0, rear = 0;
	int t = 1;
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	queue[rear] = root;
	rear = (rear + 1) % MaxSize;
	while(scanf("%d%d", &parent, &child) && t < n - 1)
	{
		p = (TreeNode*)malloc(sizeof(TreeNode));
		p->data = child;
		p->left = NULL;
		p->right = NULL;
		q = queue[front];
		while(parent != q->data)//找到父结点
		{
			front = (front + 1) % MaxSize;
			q = queue[front];
		}
		if(q->data == parent)
		{
			if(q->left == NULL)
				q->left = p;
			else
				q->right = p;
		}
 		if ((rear + 1) % MaxSize != front)//队不满，则入队
        {
            queue[rear % MaxSize] = p;//把自己的儿子放到队列中
            rear = (rear + 1) % MaxSize;
		}
		t++;
	}
	return root;
}
int node_depth(TreeNode* node, int x ,int L)
{
	int i = -1;
	if(node)
	{
		if(node->data == x)
			return L;
		if(node_depth(node->left, x, L + 1) != -1) //查左子树,如找到就返回
			return node_depth(node->left, x, L + 1);
		if(node_depth(node->right, x, L + 1) != -1)//查右子树,如找到就返回
			return node_depth(node->right, x, L + 1);
	}
	return i;
}
int height(TreeNode* p)
{
	int u, v;
	if(p == NULL)
		return 0;
	u = height(p->left);
	v = height(p->right);
	if(u > v)
		return u + 1;
	return v + 1;
}
int width(TreeNode* t)
{
	int nlast = 0, nnow = 0, nt, n = 1;
	TreeNode* p;
	queue<TreeNode*> Q;
	if(t == NULL)
		return 0;
	Q.push(t);
	nlast = 1;
	while(!Q.empty())
	{
		nt = nlast;
		while(nt)
		{
			p = Q.front();
			Q.pop();
			if(p -> left != NULL)
				Q.push(p->left);
			if(p->right != NULL)
				Q.push(p->right);
			nt--;
		}
		nnow = Q.size();
		if(n < nnow)
			n = nnow;
	}
	return n;
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	TreeNode*root;
	int n, x, y, hx, hy, h, w;
	scanf("%d", &n);
	root = CreateTree(n);
//	levelorder(root);
	h = height(root);
	w = width(root);
	scanf("%d%d", &x, &y);
//	printf("x = %d\ny = %d\n", x, y);
	hx = node_depth(root, x, 0);
	//printf("hx = %d\n", hx);
	hy = node_depth(root, y, 0);
	//printf("hy = %d\n", hy);
	printf("%d\n%d\n%d", h, w, 2 * hx + hy);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
