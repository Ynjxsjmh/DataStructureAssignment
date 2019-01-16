#include <stack>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

void menu();

class node{
	public:
		char data;
		node *firstchild;
		node *nextbrother;
};

class tree_forest{
	private:
		int judge_len;
		int len;
		int time[100];
		char pre[100];
		int judge_empty;
		void create(node* &p,char ch,int du);
		void del(node* &p);
		node *root;
		
	public:
		tree_forest(){
			judge_len=0;
			judge_empty=0;
		}
		
		~tree_forest(){
			del(root);
			printf("销毁树或森林成功!");
		}
		
		void create_tree_forest();
		
		void preorder();
		void postorder();
		void norec_preorder();
		void norec_postorder();
		void level_order();		
};

void tree_forest::create_tree_forest()
{
	judge_empty=1;
	
	printf("请输入先根序列和其度:\n");
	scanf(" %s",&pre);
	len=strlen(pre);
	for(int i=0;i<len;i++)
		scanf("%d",&time[i]);
		
	create(root,pre[judge_len],time[judge_len]);
}

void tree_forest::create(node* &p,char ch,int du)
{
	if(judge_len==len)
		return ;
	judge_len++;
	int first_time=0;
	p=new node;
	p->data=ch;
	p->firstchild=NULL;
	p->nextbrother=NULL;
	node *q;
	while(du--)
	{
		if(!first_time)
		{
			first_time=1;
			create(p->firstchild,pre[judge_len],time[judge_len]);
			q=p->firstchild;
		}
		else
		{
			create(q->nextbrother,pre[judge_len],time[judge_len]);
			q=q->nextbrother;
		}
	}
	
	q=p->nextbrother;
	while(p==root&&judge_len<len)
	{
		create(p->nextbrother,pre[judge_len],time[judge_len]);
//		q=q->nextbrother;
//		p=p->nextbrother->nextbrother;
	}
	
}

void tree_forest::preorder()
{
	static node *p=root;
	node *q=p;
	
	if(!judge_empty)
	{
		printf("根节点为空,不存在树或森林!");
		return ;
	}
	
	if(q!=NULL)
	{
		printf("%c",q->data);
		
		p=q->firstchild;
		preorder();
		
		p=q->nextbrother;
		preorder();
	}
	
	if(q==root)
		p=root;
}

void tree_forest::norec_preorder()
{
	node *p=root;
	stack<node *> s;
	
	if(!judge_empty) 
	{
		printf("根节点为空,不存在树或森林!");
		return ;
	}		
	
	while(p!=NULL||!s.empty())
	{
		while(p!=NULL)
		{
			s.push(p);
			
			printf("%c",p->data);
			
			p=p->firstchild;
		}
		
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			p=p->nextbrother;
		}
	}
}

void tree_forest::postorder()
{
	static node *p=root;
	node *q=p;
	
	if(!judge_empty) 
	{
		printf("根节点为空,不存在树或森林!");
		return ;
	}		
	
	if(p!=NULL)
	{
		p=q->firstchild;
		postorder();
		printf("%c",q->data);
		p=q->nextbrother;
		postorder();
	}
	
	if(q==root)
		p=root;
}

void tree_forest::norec_postorder()
{
	node *p=root;
	stack <node *> s;
	
	if(!judge_empty) 
	{
		printf("根节点为空,不存在树或森林!");
		return ;
	}		
	
	while(p!=NULL||!s.empty())
	{
		
		while(p!=NULL)
		{
			s.push(p);			
			p=p->firstchild;
		}
		
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			printf("%c",p->data);
			p=p->nextbrother;
		}
	}
}

void tree_forest::level_order()
{
	node *p=root;
	queue <node *> q;
	
	if(!judge_empty) 
	{
		printf("根节点为空,不存在树或森林!");
		return ;
	}		
	
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		
		while(p!=NULL)
		{
			printf("%c",p->data);
			if(p->firstchild!=NULL)
				q.push(p->firstchild);
			p=p->nextbrother;
		}
	}
}

void tree_forest::del(node* &p)
{
	if(p!=NULL)
	{
		del(p->firstchild);
		del(p->nextbrother);
		delete p;
	}
}



int main()
{
	tree_forest tree;
	int choice;
	
	menu();
	while(scanf("%d",&choice)&&choice)
	{
		switch(choice)
		{
			case 1: tree.create_tree_forest(); break;
			case 2: tree.preorder(); break;
			case 3: tree.norec_preorder(); break;
			case 4: tree.postorder(); break;
			case 5: tree.norec_postorder(); break;
			case 6: tree.level_order(); break;
		}
		printf("\n\n");
		menu();
	} 

}

void menu()
{
	printf("=======================\n");
	printf("1.创建树和森林.\n");
	printf("2.递归先根遍历树和森林.\n");
	printf("3.非递归先根遍历树和森林.\n");	
	printf("4.递归后根遍历树和森林.\n");	
	printf("5.非递归后根遍历树和森林.\n");	
	printf("6.层次遍历树和森林.\n");
	printf("0.退出.\n");
	printf("=======================\n");
}
