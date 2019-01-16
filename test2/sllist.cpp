//将单链表全部删除时会出现程序自动终止的情况 
//在调用插入数据函数时  若输入数据不为整形，程序会崩掉 

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
class sllist{
	private:
		slnode<T> *head;
		slnode<T> *tail;
		slnode<T> *cur;
		int length;
	
	public:
		sllist(){
			head=tail=cur=new slnode<T>;
			head->next=NULL;
			length=0;
		}
		void creat();
		void insert();
		void del();
		T find(T item1,T item2);
		void search();
		void output();
		void destroy();
};

void menu();

int main()
{
	sllist<int> l;
	int item1,item2,temp=0,i,len;
	char choice[1000];
	
	menu();
	
	gets(choice);
	len=strlen(choice);
	for(i=0;i<len;i++)
	{
		temp=choice[i]-'0'+temp*10;
	}
	
	while(temp<0||temp>5)
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
		    case 1:l.creat(); break;
		    case 2:l.insert(); break;
		    case 3:l.del(); break;
		    case 4:l.find(item1,item2); break;
		    case 5:l.search();break;
	    }
	    printf("\n\n\n\n");
	    menu();
	    	    
		scanf(" %s",&choice);
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}

		while(temp<0||temp>5)
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
    	l.destroy();
	}
    
	return 0;
}

template <typename T>
void sllist<T>::creat()
{
	printf("\n链表创建成功，当前含有0个元素。");
	
	output();
}


template <typename T>
void sllist<T>::insert()
{	
	char choice[100];
	int temp,i,len;
	printf("\n\n请选择您要插入数据的方式:\n");
	printf("1.在表头插入指针.\n");
	printf("2.在当前节点后插入指针.\n");
	printf("3.在表尾插入指针.\n");
	scanf(" %s",&choice);
	
	len=strlen(choice);
	temp=0;
	for(i=0;i<len;i++)
	{
		temp=choice[i]-'0'+temp*10;
	}
	
	while(temp<1||temp>3)
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
	
	if(temp==1)
	{
		int data;
		printf("请输入您想要从表头插入的数据，输入-1结束:");
		scanf(" %d",&data);
		while(data!=-1)
		{
			slnode<T> *p;
			p=new slnode<T>;
			p->data=data;
			if(head->next==NULL)
			{
				head->next=p;
				p->next=NULL;
				tail=p;
				cur=p;
				length++;
			}
			else
			{
				p->next=cur;
				head->next=p;
				cur=p;
				length++;
			}
			
			printf("是否继续插入节点，是请输入节点数据，不是请输入-1:");
			scanf(" %d",&data);		
		}		
	}
	
	
	
	if(temp==2)
	{
		int data;
		printf("请输入您想要从当前节点后插入的数据，输入-1结束:");
		scanf("%d",&data);
		while(data!=-1)		
		{
			slnode<T> *p;
			p=new slnode<T>;
			p->data=data;			
			if(cur==tail)
			{
				cur->next=p;
				p->next=NULL;
				cur=p;
				tail=p;
				length++;
			}
			if(cur!=tail)
			{
				p->next=cur->next;
				cur->next=p;
				cur=p;
				length++;
			}
						
			printf("是否继续插入节点，是请输入节点数据，不是请输入-1:");
			scanf("%d",&data);
		}
	}
	
	
	if(temp==3)
	{
		int data;
		printf("请输入您想要从表尾插入的数据，输入-1结束:");
		scanf("%d",&data);
		while(data!=-1)
		{
			slnode<T> *p;
			p=new slnode<T>;
			p->data=data;
			
			tail->next=p;
			p->next=NULL;
			cur=p;
			tail=p;
			length++;
			
			printf("是否继续插入节点，是请输入节点数据，不是请输入-1:");
			scanf("%d",&data);
		}
	}
	
	output();
}

template <typename T>
void sllist<T>::search()
{
	if(head->next==NULL)
	{
		printf("当前链表为空，无法进行查找操作!\n");
	}
	
	else
	{
		slnode<T> *p;
		int judge,flag=1,count;
		char search_data[100];
		int temp,i,len;
		int loc;
	
		while(flag)
		{
			loc=0;
			count=0;
			p=head;
		
			printf("\n\n请输入您想要查询的数据:");
			scanf(" %s",&search_data);
		
			len=strlen(search_data);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=search_data[i]-'0'+temp*10;
			}
		
			while(p!=NULL)
			{
				if(p->data==temp)
				{
					printf("所要查找的数据%s在该单链表中的位置为:%d\n\n",search_data,loc);
					count++;
					loc++;
					
					cur=p;              //当前节点指向找到的指针 
				}
				
				p=p->next;
				loc++;
     	   }
			
	 	   if(count==0)
		    {
	 		   	printf("该单链表中没有您所想要找的点!\n");
	 		   	printf("是否继续查找操作?(0表示退出查找,1表示继续查找):");
		 	   	scanf("%d",&judge);
	    	
				while(judge!=0&&judge!=1)
				{
					printf("输入数据错误，请重新输入:(0表示退出，1表示继续查找)");
					scanf("%d",&judge);
				}
			
				if(!judge)				
					flag=0;
				
				else
					flag=1;			
			}
			else
			{
				printf("是否继续查找数据？(0表示退出查找,1表示继续查找)");
				scanf("%d",&judge);
				while(judge!=0&&judge!=1)
				{
					printf("输入数据错误，请重新输入:(0表示退出，1表示继续查找)");
					scanf("%d",&judge);
				}
						
				if(!judge)				
					flag=0;
				else			
					flag=1;		
			}		
		}
	}
}

template <typename T>
T sllist<T>::find(T item1,T item2)
{
	if(head->next==NULL)
	{
		printf("当前链表为空，无法进行操作!\n");
	}
	
	else
	{
		slnode<T> *p=head->next;
		int i,temp,len;
		char k[100];
		printf("\n\n请输入您想要存取节点的下标:");
		scanf(" %s",&k);
		
		len=strlen(k);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=k[i]-'0'+temp*10;
		}	
	
		while(temp<1||temp>length)
		{
			if(temp<1)
			{
				printf("您输入的下标%s小于该链表的下界1,请重新输入:",k);
				scanf(" %s",&k);
			}
			if(temp>length)
			{
				printf("您输入下标%s大于该链表的上界%d,请重新输入:",k,length);
				scanf(" %s",&k);
			}
				len=strlen(k);
			temp=0;
			for(i=0;i<len;i++)
			{
				temp=k[i]-'0'+temp*10;
			}	
		}
	
		for(i=1;i<temp;i++)
		{
			p=p->next;
		}
	
		item1=p->data;
		item2=cur->data;
		
		printf("要查找节点的值为:%d\n",item1);
		printf("当前节点的值为:%d\n",item2);
	
		printf("要查找的数据已存入第一个实参中，当前节点的数据已存入第二个实参中.");
    }
}

template <typename T>
void sllist<T>::output()
{
	int i=1;
	slnode<T> *p=head->next;
	
	while(p!=NULL)
	{
		if(p->next==NULL)
			printf("%d",p->data);
		else
			printf("%d  ->",p->data);
		p=p->next;
		i++;
	}
	
	printf("\n当前链表长度为:%d",length);
}

template <typename T>
void sllist<T>::destroy()
{
	slnode<T> *p=head->next;
	
	while(p!=NULL)
	{
		delete head;
		head=p;
		p=p->next;
	}
	
	printf("\n销毁链表成功！");
}

template <typename T>
void sllist<T>::del()
{
	
	if(head->next==NULL)
	{
		printf("当前节点为空，无法进行删除操作！");		
	}
	
	else
	{	
		char choice[100];
		int temp,i,len;
		printf("\n\n请选择您要删除节点的方式:\n");
		printf("1.删除表头节点.\n");
		printf("2.删除表尾节点.\n");
		printf("3.删除当前节点的后继节点.\n");
		scanf(" %s",&choice);
		
		len=strlen(choice);
		temp=0;
		for(i=0;i<len;i++)
		{
			temp=choice[i]-'0'+temp*10;
		}
	
		while(temp<1||temp>3)
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
	
		if(temp==1)
		{			
			slnode<T> *p;
			if(head->next==cur&&head->next==tail)
			{		
				p=head->next;	
				head=tail;
				head=cur;
				head->next=NULL;
				delete p;
				length--;
				printf("删除节点成功！");
			}
		
			if(head->next==cur&&head->next!=tail)
			{
				p=cur;
				cur=cur->next;
			
				head->next=cur;
				delete p;
			
				length--;
				printf("删除节点成功！");
			}
		
			if(head->next!=cur)
			{
				p=head->next;
				head->next=p->next;
			
				delete p;
				length--;
			
				printf("删除节点成功！");
			}
			

		}
	
		if(temp==2)
		{
			slnode <T> *p=head;
		
			while(p->next!=tail)
			{
				p=p->next;
			}
		
			if(cur==tail)
			{
				tail=p;
				cur=p;
				p=p->next;
				delete p;
				tail->next=NULL;
				length--;
				printf("删除节点成功！");
			}
		
			if(cur!=tail)
			{
				tail=p;
				p=p->next;
				delete p;
	 	        tail->next=NULL;
				length--;
				printf("删除节点成功！");
			}		
		}	
	
		if(temp==3)
		{
			slnode<T> *p=head;
		
			if(cur==tail)
			{
				printf("当前节点为尾节点，无后继节点!");
			//	return ;
			}
		
			if(cur->next==tail)
			{
				p=cur->next;
				tail=cur;
				delete p;
				tail->next==NULL;
				length--;
				printf("删除节点成功！");			
			}
		
			else
			{
				p=cur->next;
				cur->next=p->next;
				delete p;
				length--;
				printf("删除节点成功！");
			}
		}
		printf("\n");
		output();
    }
}

void menu()
{
	printf("-----------------------------------------------------------------------------\n");
	printf("\t请选择如下您所需要的功能：\n");
	printf("* 1.创建单链表；\n");
	printf("* 2.插入操作：分别在当前结点后、表头、表尾插入值为x的结点\n");
	printf("* 3.删除操作：分别删除表头结点、表尾结点和当前结点的后继结点\n");
	printf("* 4.存取操作：分别存取当前结点的值和单链表中第k个结点的值\n");
	printf("* 5.查找操作：查找值为x的元素在单链表中出现的位置（是链表中的第几个元素）\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n请选择您所需要的功能(输入0即可退出):");
}
