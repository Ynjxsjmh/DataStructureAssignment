#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void menu();

class node{
	public:
		char data;
		node *leftchild;
		node *rightchild;
};

class binary_tree{
	private:
		int judge;
		node *root;
		void create(node * &p);
		void del(node* &p);
		node *father(node *p,char ch);
		node *search(node *p,char ch);
		
	public:
		binary_tree(){
			judge=0;
		}
		
		~binary_tree(){
			del(root);
			root=NULL;
			printf("���������ٳɹ�!");
		}
		
		void create_binary_tree();
		
		void preorder();
		void inorder();
		void postorder();
		void norec_preorder();
		void norec_inorder();
		void norec_postorder();
		void level_order();
		
		void find_father();
		void find_target();
		
		void dst();
};

void binary_tree::create(node* &p)
{
	judge=1;
	char ch;
	cin>>ch;
	
	if(ch=='#')
		p=NULL;
	else
	{
		p=new node ;
		p->data=ch;
		create(p->leftchild);
		create(p->rightchild);
	}
}

void binary_tree::create_binary_tree()
{
	printf("������һ����չ�ȸ�����:");
	create(root);
}

void binary_tree::preorder()
{
	static node *p=root;
	node *q=p;
	
	if(!judge) 
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}	
	
	if(p!=NULL)
	{
		cout<<q->data;
		
		p=q->leftchild;
		preorder();
		
		p=q->rightchild;
		preorder();
	}
	
	if(q==root)
		p=root;
}

void binary_tree::inorder()
{
	static node *p=root;
	node *q=p;
	
	if(!judge) 
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}	
	
	if(p!=NULL)
	{
		p=q->leftchild;	
		inorder();
		cout<<q->data;
		p=q->rightchild;
		inorder();
	}
	
	if(q==root)
		p=root;
}

void binary_tree::postorder()
{
	static node *p=root;
	
	node *q=p;
	
	if(!judge) 
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}
	
	if(p!=NULL)
	{
		p=q->leftchild;
		postorder();
		
		p=q->rightchild;
		postorder();
		
		cout<<q->data;
	}
	
	if(q==root)
		p=root;
}

void binary_tree::norec_preorder()
{
	node *p=root;
	stack <node *> s;
	
	if(!judge) 
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}
	
	while(p!=NULL||!s.empty())
	{
		while(p!=NULL)
		{
			cout<<p->data;
			s.push(p);
			p=p->leftchild;
		}
		
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			p=p->rightchild;
		}
	}
}

void binary_tree::norec_inorder()
{
	node *p=root;
	stack <node *> s;
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}	
	
	while(p!=NULL||!s.empty())
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->leftchild;
		}
		
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			cout<<p->data;
			p=p->rightchild;
		}
	}
}


void binary_tree::norec_postorder()
{
	node *p=root;
	node *pre=NULL;
	stack<node *> s;
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}	
	
	while(p!=NULL||!s.empty())
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->leftchild;
		}
		
		p=s.top();
		
		if(p->rightchild==NULL||p->rightchild==pre)
		{
			cout<<p->data;
			pre=p;
			s.pop();
			p=NULL;
		}
		else
			p=p->rightchild;
	}
}

void binary_tree::find_father()
{
	queue <node *> q;
	node *p=root;
	int i=0;
	char ch;
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}	
	
	printf("����������Ҫ���ҽڵ��ֵ:");
	scanf(" %c",&ch);
	
	if(p->data==ch)
		printf("�ýڵ�Ϊ���ڵ�,�޸��׽ڵ�!");
	
	else
	{
		if(p!=NULL)
			q.push(p);
		
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			
			if(p->leftchild!=NULL)
			{
				q.push(p->leftchild);
				if(p->leftchild->data==ch)
				{
					i++;
					printf("���׽ڵ�Ϊ:%c",p->data);
				}
			}
			
			if(p->rightchild!=NULL)
			{
				q.push(p->rightchild);
				if(p->rightchild->data==ch)
				{
					i++;	
					printf("���׽ڵ�Ϊ:%c",p->data);
				}
			}
		}
	}
	
	if(!i)
	{
		printf("������Ľڵ㲻�ڸö�������!");
	}
}

node *binary_tree::father(node *p, char ch)
{
	queue <node *> q;
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		exit(0);
	}
	
	if(p!=NULL)
		q.push(p);
	
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		
		if(p->leftchild!=NULL)
		{
			q.push(p->leftchild);
			if(p->leftchild->data==ch)
				return p;
		}
		
		if(p->rightchild!=NULL)
		{
			q.push(p->rightchild);
			if(p->rightchild->data==ch)
				return p;
		}	
	}
	return NULL;
} 

node *binary_tree::search(node *p,char ch)
{
	queue <node *> q;
	
	if(p!=NULL)
		q.push(p);
	
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		
		if(p->data==ch)
			return p;
		
		if(p->leftchild!=NULL)
			q.push(p->leftchild);
		if(p->rightchild!=NULL)
			q.push(p->rightchild);
	}
	return NULL;
}

void binary_tree::del(node* &p)
{
	if(p!=NULL)
	{
		del(p->leftchild);
		del(p->rightchild);
		delete p;
	}
}

void binary_tree::dst()
{
	node* &t=root;
	node *p,*q;
	char ch; 
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}
	
	printf("��������Ҫɾ���Ľڵ�:");
	scanf(" %c",&ch);
	
	p=search(t,ch);
	
	if(p==NULL)
		return ;
	
	if(p==t)
	{
		del(p);
		judge=0;
		return ;
	}
	
	q=father(t,ch);
	
	if(q!=NULL&&q->leftchild==p)
		q->leftchild=NULL;
	if(q!=NULL&&q->rightchild==p)
		q->rightchild=NULL;
	
	del(p);
}

void binary_tree::find_target()
{
	node *p=root;
	char a;
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}
	
	printf("��������Ҫ���ҵ�����:");
	cin>>a;
	
	queue <node *> q;
	
	if(p!=NULL)
		q.push(p);
		
	if(p->data==a)
	{
		printf("�����ҵĽڵ�%cΪ���ڵ�.",p->data);
		return ;
	}
	
	while(!q.empty())
	{
		p=q.front();
		
		if(p->leftchild!=NULL)
		{
			q.push(p->leftchild);
			if(p->leftchild->data==a)
			{
				cout<<p->leftchild->data<<"�ĸ��ڵ�Ϊ"<<p->data;
				return ;
			}
		}
		
		if(p->rightchild!=NULL)
		{
			q.push(p->rightchild);
			if(p->rightchild->data==a)
			{
				cout<<p->rightchild->data<<"�ĸ��ڵ�Ϊ"<<p->data;
				return ;
			}
		}
		
		q.pop();
	} 
	printf("�������Ľڵ㲻�ڸö�������!");
}

void binary_tree::level_order()
{
	node *p=root;
	queue<node *> q;
	
	if(!judge)
	{
		printf("���ڵ�Ϊ��,�����ڶ�����!");
		return ;
	}
	
	if(p!=NULL)
		q.push(p);
	
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p->data;
		if(p->leftchild!=NULL)
			q.push(p->leftchild);
		if(p->rightchild!=NULL)
			q.push(p->rightchild);
	}
}


int main()
{
	binary_tree bt;
	int choice;
	menu();
	while(scanf("%d",&choice)&&choice)
	{
		switch(choice)
		{
			case 1: bt.create_binary_tree(); break;
			case 2: bt.preorder(); break;
			case 3: bt.inorder(); break;
			case 4: bt.postorder(); break;
			case 5: bt.norec_preorder(); break;
			case 6: bt.norec_inorder(); break;
			case 7: bt.norec_postorder(); break;
			case 8: bt.level_order(); break;
			case 9: bt.find_father(); break;
			case 10: bt.find_target(); break;
			case 11: bt.dst(); break;
		}
		printf("\n\n");
		menu();
	} 
	
//	bt.create_binary_tree();
//	bt.dst();
//	bt.norec_preorder();
//	bt.inorder();
//	bt.preorder(); 
	
	return 0;
}



void menu()
{
	printf("=========================\n");
	printf("��ѡ������Ҫʵ�ֵĹ���:\n");
	printf("1.����������.\n");
	printf("2.�ݹ��ȸ�����������.\n");
	printf("3.�ݹ��и�����������.\n");
	printf("4.�ݹ�������������.\n");
	printf("5.�ǵݹ��ȸ�����������.\n");
	printf("6.�ǵݹ��и�����������.\n");
	printf("7.�ǵݹ�������������.\n");
	printf("8.��α���������.\n");
	printf("9.�������ڵ�.\n");
	printf("10.�������������������Ľڵ�.\n");
	printf("11.ɾ���ڵ㼰������.\n");
	printf("0.�˳�.\n");
	printf("=========================\n");
}
