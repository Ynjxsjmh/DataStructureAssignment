#include<iostream>
#include<string>
using namespace std;

struct BTreeNode
{
	char data;
	BTreeNode *LChild;
	BTreeNode *RChild;
};

void PreOrder(BTreeNode *t); 
BTreeNode *RecoveryTree(string s1, string s2);
void DestroyTree(BTreeNode *t);  

int main()
{
	freopen("preorder.in","r",stdin);
    freopen("preorder.out","w",stdout);
	string s1,s2;
	cin>>s2>>s1;
	BTreeNode *root;
	root=RecoveryTree(s1,s2);
	PreOrder(root);
	return 0;
}
 
void PreOrder(BTreeNode *t)
{
	if(t==NULL)
		return;
	cout<<t->data;
	PreOrder(t->LChild);
	PreOrder(t->RChild);
} 

BTreeNode *RecoveryTree(string s1, string s2)//s1后根 s2中根 
{
	//初始化：数据为先根序列的s1[0]，左右子树指针为空 
	BTreeNode *root=new BTreeNode;
	root->data=s1[s1.size()-1];
	root->LChild=NULL;
	root->RChild=NULL;
	//确定根在中根序列中的位置index 
	int index=0;
	for(int i=0;i<s2.size();i++)
	{
		if(root->data==s2[i])
		{
			index=i;
			break;
		}
	}
	//递归求根的左右子树 
	if(index>0)
		root->LChild=RecoveryTree(s1.substr(0,index),s2.substr(0,index));
	if(index<s2.size()-1)
		root->RChild=RecoveryTree(s1.substr(index,s1.size()-1-(s1.substr(0,index)).size()),s2.substr(index+1));
	//返回根结点指针 
	return root;
}

