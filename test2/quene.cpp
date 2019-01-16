#include <cstring>
#include <iostream>
using namespace std;

template <typename T>
class slnode{
	public:
		T data;
		slnode<T> *next;
};

template <typename T>
class squeue{
	private:
		slnode<T> *front;
		slnode<T> *rear;
		int length;
	public:
		squeue(){
			front=rear=new slnode<T>;
			front->next=NULL;
			length=0;
		}
		void creat();
		void insert();
		void del();                 //删除队首 
		T find();
		T gettop();                 //取队首操作 
		T out();                    //取队首并将头结点后移，及将队首弹出队列 
		void output();              //输出队列的所有数据 
		void destory();              //销毁队列中的链表 
};

void menu();

int main()
{
	int top,temp,len,i;
	squeue<int> q;
	char choice[1000];

	menu();
	
	temp=0;
	gets(choice);
	len=strlen(choice);
	for(i=0;i<len;i++)
	{
		temp=choice[i]-'0'+temp*10;
	}
	
	while(temp<0||temp>4)
	{
		printf("您的选择是:%s,选择不属于上述任何一种,请重新输入:",choice);
		scanf(" %s",&choice);
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}
	}
	
	while(temp)
	{
		switch(temp)
		{
			case 1:q.creat(); break;
			case 2:q.insert(); break;
			case 3:q.del();  break;
			case 4:top=q.gettop();
		}
		menu();
	    
	    
		scanf(" %s",&choice);
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}

		while(temp<0||temp>4)
		{
			printf("您的选择是:%s,选择不属于上述任何一种,请重新输入:",choice);
			scanf(" %s",&choice);
			len=strlen(choice);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=choice[i]-'0'+temp*10;
			}
		}		
	}
	
	if(!temp)
	{
		q.destory();
	}	                             
	return 0;
}

template <typename T>
void squeue<T>::creat()
{
	printf("创建队列成功！当前含有0个元素。\n\n");
}

template <typename T>
void squeue<T>::insert()
{
	T x;
	int judge;
	
	cout<<"请输入您要向队尾插入的值:";
	cin>>x;
	
	while(x!=-1)
	{
		if(length==0)
		{
			front->data=x;
			printf("节点入队成功！\n\n");
			length++;
		}	
		else
		{
			slnode<T> *q;
			q=new slnode<T>;
			q->data=x;
			rear->next=q;
			rear=q;
			rear->next=NULL;
			length++;
			
			printf("节点入队成功！\n\n");
		}		
		cout<<"是否继续插入节点？（是输入数据，不是输入-1）:";
		cin>>x;		
	}
	
	printf("\n");
	output();
}

template <typename T>
void squeue<T>::del()
{
	if(length==0)
	{
		printf("队列为空，无法进行删除操作！\n");
	}
	
	else
	{
		slnode<T> *p=front;
		front=front->next;
		
		delete p;		
		length--;
		
		printf("删除队首元素成功！\n\n");
		
		if(length==0)
		{
			printf("该队列已被销毁，无法继续进行操作!\n\n");
			exit(0);
		}
	}
	output();
}

template <typename T>
T squeue<T>::find()
{
	cout<<"队首元素为："<<front->data;
	printf("队首元素读取成功!");	
	return front->data;
}

template <typename T>
T squeue<T>::out()
{
	slnode<T> *p=front;
	T x;
	
	if(length==0)
		printf("队列为空！无法进行弹队首操作.");
	else
	{
		x=p->data;
		front=front->next;
		delete p;
		length--;
		return x;
	}

}

template <typename T>
void squeue<T>::output()
{
	slnode<T> *p=front;
	while(p!=NULL)
	{
		if(p->next==NULL)
			printf("%d",p->data);
		else
			printf("%d ->",p->data);
		p=p->next;
	}
	
	printf("\n");
}

template <typename T>
T squeue<T>::gettop()
{
	if(length==0)
	{
		printf("队列为空，无法进行取队首操作!");
	}
	else
	{
		printf("队首元素为:%d\n",front->data);
		return front->data; 		
	}

}

template <typename T>
void squeue<T>::destory()
{
	slnode<T> *p;
	p=front;
	while(p!=NULL)
	{
		p=p->next;
		delete front;
		front=p;
	}
	
	printf("\n销毁队列成功!\n");
}

void menu()
{
	printf("--------------------------------------\n");
	printf("请输入您的选择:\n");
	printf("* 1.创建队列\n");
	printf("* 2.插入操作：向队尾插入值为x的元素\n");
	printf("* 3.删除操作：删除队首元素\n");
	printf("* 4.存取操作：读取队首元素\n");
	printf("* 0.退出操作\n");
	printf("--------------------------------------\n");	
	printf("请您选择您想要的功能:");
}
