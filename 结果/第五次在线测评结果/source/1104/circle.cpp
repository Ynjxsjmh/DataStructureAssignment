/*�����롿
��һ�а���һ������n����ʾԲ����Ŀ��
���µ�n �У�ÿ��3 ���ÿո��������x��y��r����x��y����Բ�����꣬r �ǰ뾶�����е����꼰�뾶���ǲ�����30000 �ķǸ�������
�������
��ЩԲ���γɵĲ�ͬ�Ŀ����Ŀ��
*/
//Բ�ľ࣬�뾶�ͣ��뾶��
//����һ���������ָ�������ָ��

#include<iostream>
#include<fstream>
using namespace std;

#define cin fin
#define cout fout

ifstream fin("circle.in");
ofstream fout("circle.out");



struct Node    //��������
{
	int data[3];     //��������һ�����飬���x,y,r
	Node *next;     //ָ����ָ����һ�����
	Node(Node *nextNode = NULL)   //���캯��������ָ����next���г�ʼ����Ĭ��Ϊ��ָ�룬��û��ָ������data��ֵ
	{
		next = nextNode;
	}
	Node(int m,int n,int p, Node * nextNode = NULL)    //���캯������data��next�������˳�ʼ��
	{
		data[0] = m;
		data[1] = n;
		data[2] = p;
		next = nextNode;
	}
};
class List      //����ÿһ��Բ������
{
private:
	Node *head;   //����ָ��
public:
	List(int a, int b, int c);    //�����ԣ�a,b,c��Ϊ���׵�����
	List(void);   
	~List() { head = NULL; }
	void Insert(int a, int b, int c);
	Node* Head() { return head; }
};

List::List(int a, int b, int c)
{
	head = new Node(a, b, c, NULL);
}

List::List(void)
{
	head = new Node();
}

void List::Insert(int a, int b, int c)
{
	Node *p = head;
	while (p ->next!= NULL)
	{
		p = p->next;
	}
	p->next = new Node(a, b, c, NULL);
}


int main(void)
{
	int n;
	int x, y, r;   //��x,y����ʾԲ�����꣬r��ʾ�뾶
	int x1, y1, r1;    //��ʾ��ǰ�����Բ�����Ƚ��ж��Ƿ�Ϊ�µ�һ��Բ
	List b[7000];   //��Ų�ͬ���Բ
	int k = 0;    //Բ�Ŀ���
	int flag;
	cin >> n;
	cin >> x >> y >> r;    //��һ�������Բ
	List temp(x, y, r);
	b[0] = temp;
	k++;
	for (int i = 1; i < n; i++)     //������n-1������
	{
		cin >> x1 >> y1 >> r1;
		flag = 0;     //δ�ҵ��ཻ��
		for (int j = 0; j < k; j++)   //�ұ����е������ұ�k����ͬ�Ŀ�
		{
			if (flag == 0)    //��δ�ҵ�
			{
				Node *p = b[j].Head();
				while (p != NULL)   //�ұ�һ���������е�Բ
				{
					if (((((p->data[0]) - x1)*((p->data[0]) - x1) + ((p->data[1]) - y1)*((p->data[1]) - y1)) <= ((r1 + (p->data[2]))*(r1 + (p->data[2])))))
					{
						b[j].Insert(x1, y1, r1);
						flag = 1;
						break;
					}
					p = p->next;
				}
			}
		}
		if (flag == 0)    //δ�ҵ��ཻ��
		{
			List temp1(x1, y1, r1);
			b[k] = temp1;
			k++;
		}
	}
	cout << k << endl;
	return 0;
}

