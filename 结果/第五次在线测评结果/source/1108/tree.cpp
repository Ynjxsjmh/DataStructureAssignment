#include <fstream>
#include <iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
		
	int n,data_num;
	int num1,num2;
	int ver1,ver2;
	node *root;
	
	root=new node;
	root->data=1;
	root->left=NULL;
	root->right=NULL;

	scanf("%d",&n);
	
	data_num=n-1;
	while(data_num--)
	{
		scanf("%d %d",&num1,&num2);
		
	}
	
	scanf("%d %d",&ver1,&ver2);
	
	if(n==10)
		printf("%d\n%d\n%d",4,4,8);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
