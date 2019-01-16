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
		void del();                 //ɾ������ 
		T find();
		T gettop();                 //ȡ���ײ��� 
		T out();                    //ȡ���ײ���ͷ�����ƣ��������׵������� 
		void output();              //������е��������� 
		void destory();              //���ٶ����е����� 
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
		printf("����ѡ����:%s,ѡ�����������κ�һ��,����������:",choice);
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
			printf("����ѡ����:%s,ѡ�����������κ�һ��,����������:",choice);
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
	printf("�������гɹ�����ǰ����0��Ԫ�ء�\n\n");
}

template <typename T>
void squeue<T>::insert()
{
	T x;
	int judge;
	
	cout<<"��������Ҫ���β�����ֵ:";
	cin>>x;
	
	while(x!=-1)
	{
		if(length==0)
		{
			front->data=x;
			printf("�ڵ���ӳɹ���\n\n");
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
			
			printf("�ڵ���ӳɹ���\n\n");
		}		
		cout<<"�Ƿ��������ڵ㣿�����������ݣ���������-1��:";
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
		printf("����Ϊ�գ��޷�����ɾ��������\n");
	}
	
	else
	{
		slnode<T> *p=front;
		front=front->next;
		
		delete p;		
		length--;
		
		printf("ɾ������Ԫ�سɹ���\n\n");
		
		if(length==0)
		{
			printf("�ö����ѱ����٣��޷��������в���!\n\n");
			exit(0);
		}
	}
	output();
}

template <typename T>
T squeue<T>::find()
{
	cout<<"����Ԫ��Ϊ��"<<front->data;
	printf("����Ԫ�ض�ȡ�ɹ�!");	
	return front->data;
}

template <typename T>
T squeue<T>::out()
{
	slnode<T> *p=front;
	T x;
	
	if(length==0)
		printf("����Ϊ�գ��޷����е����ײ���.");
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
		printf("����Ϊ�գ��޷�����ȡ���ײ���!");
	}
	else
	{
		printf("����Ԫ��Ϊ:%d\n",front->data);
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
	
	printf("\n���ٶ��гɹ�!\n");
}

void menu()
{
	printf("--------------------------------------\n");
	printf("����������ѡ��:\n");
	printf("* 1.��������\n");
	printf("* 2.������������β����ֵΪx��Ԫ��\n");
	printf("* 3.ɾ��������ɾ������Ԫ��\n");
	printf("* 4.��ȡ��������ȡ����Ԫ��\n");
	printf("* 0.�˳�����\n");
	printf("--------------------------------------\n");	
	printf("����ѡ������Ҫ�Ĺ���:");
}
