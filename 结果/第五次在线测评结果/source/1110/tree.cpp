#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
void cbt(node* t)
{
	char c;
	cin>>c;
	if(c=='#')
	{
		t=NULL;
		return;
	}else
	{
		t=new node;
		scanf("%d",&t->data);
	}
	cbt(t->left);
	cbt(t->right);
}
void preorder(node*t)
{
	/*if(t==NULL)
	{
		return;
	}else
	{
		cout<<t->data;
	}
	preorder(t->left);
	preorder(t->right);*/
	if(t!=NULL)
	{
		preorder(t->left);
		cout<<t->data;
		preorder(t->right);
	}
}
int main()
{
	//freopen("text.txt","r",stdin);
	node* t=new node;
	t->data=1;
	cbt(t);
	preorder(t);
}
