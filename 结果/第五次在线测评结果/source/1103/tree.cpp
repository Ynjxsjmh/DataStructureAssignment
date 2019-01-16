#include<iostream>
#include <fstream>
#include<queue>
using namespace std;
#define cin fin
#define cout fout

ifstream fin("tree.in");
ofstream fout("tree.out");
template<class T>
class BinTreeNode
{
private:
	BinTreeNode<T> *left,*right;
	T data;
public:
	BinTreeNode(const T&item,BinTreeNode<T>*lptr=NULL,BinTreeNode<T>*rptr=NULL)
	:data(item),left(lptr),right(rptr){} //���캯��
	BinTreeNode(BinTreeNode<T>* p):data(p->GetData()),left(p->GetLeft()),right(p->GetRight()){}
	BinTreeNode<T>* GetLeft(void)const{return left;}//�������ӽڵ�
	void SetLeft(BinTreeNode<T> *L){left=L;}//��������
	BinTreeNode<T>* GetRight(void)const{return right;} //�������ӽڵ�
	void SetRight(BinTreeNode<T> *R){right=R;}//�������ӽڵ�
	T& GetData(){return data;}
	void SetData(const T&item){data=item;}
	void Print_Node(BinTreeNode<T>* t){
		cout<<t->data;
	}
 };
//��������BinTree������
template<class T>
class BinTree
{
private:
	BinTreeNode<T> *root;//ָ����������ڵ��ָ��
	//T stop;//���������ʱ�������������������stop��ֹͣ����
public:
    BinTree(BinTreeNode<T> *t=NULL):root(t){} //���캯��
//	virtual ~BinTree(){Del(root);}
	//���Խ��tΪ�������������������p�ĸ��ڵ�
	BinTreeNode<T>* Father(BinTreeNode<T> *t,BinTreeNode<T> *p);
	// ���Խ��tΪ����������������data��Ϊitem�Ľڵ�
	BinTreeNode<T>* Find(BinTreeNode<T> *t,const T&item)const;
	void CreateBinTree(T tostop);//����������
	BinTreeNode<T>* Create(int n);
	void LevelOrder(BinTreeNode<T>* t)const;
	void PreOrder(BinTreeNode<T>* t)const;
	BinTreeNode<T>* GetRoot(){return root;}
	void SetRoot(BinTreeNode<T> *t){root=t;}
	int IsEmpty(){return root==NULL?1:0;}
	void Debug(){cout<<"*********************"<<endl;}
 };
 template<class T>
 BinTreeNode<T>* BinTree<T>::Find(BinTreeNode<T>* t,const T&item)const
{
	BinTreeNode<T> *p,*q;
	if(t==NULL) return NULL;
	if(t->GetData()==item) return t;
	if((p=Find(t->GetLeft(),item))!=NULL) return p;
	else return q=Find(t->GetRight(),item);
 }
//����һ�Ŷ������������ض����������
template<class T>
BinTreeNode<T>* BinTree<T>::Create(int w)
{
    //if(t==NULL) return;
    int m=w;
    queue<BinTreeNode<T>* > s;
    BinTreeNode<T> *p,*q,*n,*t;
    T i,j;
    cin>>i>>j;
    p=new BinTreeNode<T>(i);
    s.push(p);
    q=new BinTreeNode<T>(j);
    s.push(q);
    p->SetLeft(q);
    //Debug();
    while(m)
    {

        //n=s.front();
        //s.pop();
        //cout<<n->GetData()<<endl;
        cin>>i>>j;
        n=Find(p,i);
        if((n->GetLeft())==NULL)
        {
            q=new BinTreeNode<T>(j);
            n->SetLeft(q);
            //s.push(q);
        }
        else{
            q=new BinTreeNode<T>(j);
            n->SetRight(q);
            //s.push(q);
        }
        --m;
    }
    Debug();
    return p;
}
template<class T>
void BinTree<T>::LevelOrder(BinTreeNode<T>* t)const
{
    if(t==NULL) return;
    queue<BinTreeNode<T>* > s;
    BinTreeNode<T> *p,*n;
    p=t;
    s.push(t);
    while(!s.empty())
    {

        n=s.front();
        s.pop();
        cout<<n->GetData()<<endl;
        if((n->GetLeft())!=NULL) s.push(n->GetLeft());
        if((n->GetRight())!=NULL) s.push(n->GetRight());
    }
//    Debug();
}
template<class T>
void BinTree<T>::PreOrder(BinTreeNode<T>* t)const
{
	if(t!=NULL)
	{
		cout<<t->GetData()<<endl;
		PreOrder(t->GetLeft());
		PreOrder(t->GetRight());
	}
}
int main(void)
{
    BinTree<int> p;
    int n,a,b;
    cin>>n;
    BinTreeNode<int> m(p.Create(n));
    BinTreeNode<int>* t;
    t=&m;
    p.PreOrder(t);
   // cin>>a,b;
   // p.LevelOrder(t,a,b);
}
