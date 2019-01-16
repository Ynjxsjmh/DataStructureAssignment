/*【输入】
第一行包括一个整数n，表示圆的数目。
以下的n 行，每行3 个用空格隔开的数x，y，r。（x，y）是圆心坐标，r 是半径。所有的坐标及半径都是不大于30000 的非负整数。
【输出】
这些圆所形成的不同的块的数目。
*/
//圆心距，半径和，半径差
//设置一个链表，存放指向数组的指针

#include<iostream>
#include<fstream>
using namespace std;

#define cin fin
#define cout fout

ifstream fin("circle.in");
ofstream fout("circle.out");



struct Node    //链表结点类
{
	int data[3];     //数据域是一个数组，存放x,y,r
	Node *next;     //指针域指向下一个结点
	Node(Node *nextNode = NULL)   //构造函数，仅对指针域next进行初始化，默认为空指针，而没有指定数据data的值
	{
		next = nextNode;
	}
	Node(int m,int n,int p, Node * nextNode = NULL)    //构造函数，对data和next都进行了初始化
	{
		data[0] = m;
		data[1] = n;
		data[2] = p;
		next = nextNode;
	}
};
class List      //保存每一块圆的链表
{
private:
	Node *head;   //链首指针
public:
	List(int a, int b, int c);    //创建以（a,b,c）为链首的链表
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
	int x, y, r;   //（x,y）表示圆心坐标，r表示半径
	int x1, y1, r1;    //表示当前输入的圆，作比较判断是否为新的一块圆
	List b[7000];   //存放不同块的圆
	int k = 0;    //圆的块数
	int flag;
	cin >> n;
	cin >> x >> y >> r;    //第一个输入的圆
	List temp(x, y, r);
	b[0] = temp;
	k++;
	for (int i = 1; i < n; i++)     //再输入n-1组数据
	{
		cin >> x1 >> y1 >> r1;
		flag = 0;     //未找到相交的
		for (int j = 0; j < k; j++)   //找遍所有的链表，找遍k个不同的块
		{
			if (flag == 0)    //还未找到
			{
				Node *p = b[j].Head();
				while (p != NULL)   //找遍一个块中所有的圆
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
		if (flag == 0)    //未找到相交的
		{
			List temp1(x1, y1, r1);
			b[k] = temp1;
			k++;
		}
	}
	cout << k << endl;
	return 0;
}

