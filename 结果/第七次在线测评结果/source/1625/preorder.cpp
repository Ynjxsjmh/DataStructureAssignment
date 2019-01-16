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

BTreeNode *RecoveryTree(string s1, string s2)//s1��� s2�и� 
{
	//��ʼ��������Ϊ�ȸ����е�s1[0]����������ָ��Ϊ�� 
	BTreeNode *root=new BTreeNode;
	root->data=s1[s1.size()-1];
	root->LChild=NULL;
	root->RChild=NULL;
	//ȷ�������и������е�λ��index 
	int index=0;
	for(int i=0;i<s2.size();i++)
	{
		if(root->data==s2[i])
		{
			index=i;
			break;
		}
	}
	//�ݹ�������������� 
	if(index>0)
		root->LChild=RecoveryTree(s1.substr(0,index),s2.substr(0,index));
	if(index<s2.size()-1)
		root->RChild=RecoveryTree(s1.substr(index,s1.size()-1-(s1.substr(0,index)).size()),s2.substr(index+1));
	//���ظ����ָ�� 
	return root;
}

