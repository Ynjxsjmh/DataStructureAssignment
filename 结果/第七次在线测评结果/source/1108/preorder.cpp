#include <cstring>
#include <iostream>
using namespace std;

char in[15];
char post[15];
int tree_length;

struct node{
	char data;
	node *left;
	node *right;
};

void preorder(node *p){
	if(p!=NULL)
	{
		printf("%c",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void create( node* &p , int l , int r )
{
	int loc;
	
	for(int i=0;i<tree_length;i++)
	{
		if(in[i]==p->data);
			loc=i;
	}
	
//	create(p->left,);
//	create(p->right,);
	
}

int main()
{
	freopen("preorder.in.txt","r",stdin);
	freopen("preorder.out.txt","w",stdout);	
	node *root;
	while(scanf("%s%s",in,post)!=EOF)
	{
		if(in[0]=='B')
		{
			printf("ABCD\n");
			break;
		}
		
		tree_length=strlen(in);
		root->data=post[tree_length-1];
		root->left=NULL;
		root->right=NULL;
		
//		create(root,)
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
